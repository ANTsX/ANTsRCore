// Connects the ANTs console streams of antsr_redirect.h to the R console.
// This runs when ANTsRCore.so is loaded, which R does on its main thread.
#include <thread>

#include <R_ext/Print.h>

#include "antsr_redirect.h"

namespace
{
const std::thread::id main_thread = std::this_thread::get_id();

// R's API may only be called from R's main thread, so output from ITK worker
// threads is dropped.
void
r_console_write(const char * s, int n, bool err)
{
  if (std::this_thread::get_id() != main_thread)
    return;
  if (err)
    REprintf("%.*s", n, s);
  else
    Rprintf("%.*s", n, s);
}

[[maybe_unused]] const bool connected = (antsr_console_write = &r_console_write, true);
} // namespace
