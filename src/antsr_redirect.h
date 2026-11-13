// Force-included (-include) into every C++ file of the bundled ANTs build by
// configure. R CMD check warns when compiled code uses std::cout/std::cerr,
// the C library rand()/srand() or sprintf(); ANTs uses them in ~175 files.
// Rather than patching each file, rename them here to replacements that write
// to the R console, keep a private random number state and bound the write.
//
// Everything is an inline (C++17) definition, so no extra object file is
// needed, also for packages that link the installed ANTs libraries.
#ifndef ANTSR_REDIRECT_H
#define ANTSR_REDIRECT_H

#ifdef __cplusplus

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <streambuf>
#include <thread>

extern "C" {
void Rprintf(const char *, ...);
void REprintf(const char *, ...);
}

// Writes to the R console. R's API may only be called from R's main thread,
// so output from ITK worker threads is dropped. The shared object is loaded
// on the main thread, which is when this id is initialized.
inline const std::thread::id antsr_main_thread = std::this_thread::get_id();

class antsr_console_buf : public std::streambuf
{
public:
  explicit antsr_console_buf(bool err)
    : m_err(err)
  {}

protected:
  int_type
  overflow(int_type c) override
  {
    if (c != traits_type::eof())
    {
      char ch = traits_type::to_char_type(c);
      xsputn(&ch, 1);
    }
    return traits_type::not_eof(c);
  }

  std::streamsize
  xsputn(const char * s, std::streamsize n) override
  {
    if (n > 0 && std::this_thread::get_id() == antsr_main_thread)
    {
      if (m_err)
        REprintf("%.*s", static_cast<int>(n), s);
      else
        Rprintf("%.*s", static_cast<int>(n), s);
    }
    return n;
  }

private:
  bool m_err;
};

inline antsr_console_buf antsr_cout_buf{ false };
inline antsr_console_buf antsr_cerr_buf{ true };
inline std::ostream      antsr_cout{ &antsr_cout_buf };
inline std::ostream      antsr_cerr{ &antsr_cerr_buf };

// Park-Miller minimal standard generator (as std::minstd_rand), seeded like
// rand() with 1, scaled to 0..RAND_MAX.
inline unsigned long antsr_rand_state = 1;

inline void
antsr_srand(unsigned int seed)
{
  antsr_rand_state = seed % 2147483647UL;
  if (antsr_rand_state == 0)
    antsr_rand_state = 1;
}

inline int
antsr_rand()
{
  antsr_rand_state = (antsr_rand_state * 48271UL) % 2147483647UL;
  return static_cast<int>(antsr_rand_state % (static_cast<unsigned long>(RAND_MAX) + 1UL));
}

// sprintf through vsnprintf, sized by a first pass.
inline int
antsr_sprintf(char * buf, const char * fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  va_list ap2;
  va_copy(ap2, ap);
  const int n = std::vsnprintf(nullptr, 0, fmt, ap);
  va_end(ap);
  const int r = n < 0 ? n : std::vsnprintf(buf, static_cast<size_t>(n) + 1, fmt, ap2);
  va_end(ap2);
  return r;
}

// So both std::cout and cout (after using namespace std) resolve.
namespace std
{
using ::antsr_cerr;
using ::antsr_cout;
using ::antsr_rand;
using ::antsr_sprintf;
using ::antsr_srand;
} // namespace std

// The standard headers above are already included, so their declarations are
// unaffected; function-like macros leave names such as `using ::rand;` alone.
#define cout antsr_cout
#define cerr antsr_cerr
#define rand() antsr_rand()
#define srand(seed) antsr_srand(seed)
#define sprintf(...) antsr_sprintf(__VA_ARGS__)

#endif // __cplusplus

#endif // ANTSR_REDIRECT_H
