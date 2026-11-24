# Where the compile/link flags come from

Flags used when building ANTsRCore, by origin. (`configure` = Unix/macOS,
`configure.win` = Windows.)

## ITKR (`ITKR:::itkCompileFlags()`, `itkIncludes()`, `itkLibs()`)
Read by both configure scripts and passed to CMake (`CMAKE_C_FLAGS` /
`CMAKE_CXX_FLAGS`) when building ANTs:

- all platforms: `-fPIC -O2`
- Windows only: `-lws2_32 -lgdi32 -mwindows -msse4.1 -mssse3 -Wa,-mbig-obj`
- include dir (`-I${ITK}`) and static library dir (`-L`/`lib*.a` for ITK)

`configure.win` post-filters these: drops `-msse4.1 -mssse3` on non-x86
(arm64 clang rejects them) and drops the link-only `-l*`/`-mwindows` from the
*compile* flags (clang warns "linker input unused"; they are still passed at
link time through `ADD_PKG_LIBS`).

Note: the ITKR companion PR
([ANTsX/ITKR#85](https://github.com/ANTsX/ITKR/pull/85), not yet merged)
makes `itkCompileFlags()` compile-only (no `-l*`/`-mwindows`) and adds `-msse4.1 -mssse3` only on x86. webR/wasm uses the
unix path (`-fPIC -O2`, emcmake). ITKR's own `configure.win` gates the Windows
flags behind `ITKR_ENABLE_WINDOWS_*` (default off), so ITK is built with
`-O2 -DNDEBUG` only.

## ANTsRCore (added by `configure` / `configure.win`)
- Compile (`PKG_CPPFLAGS`/`PKG_CXXFLAGS`/CMake): `-ffunction-sections
  -fdata-sections`, `-DNDEBUG`, `-D_FILE_OFFSET_BITS=64` (Windows C),
  `-fvisibility=hidden -fvisibility-inlines-hidden` (Windows), `-Wa,-mbig-obj`
  (Windows), `-isysroot <sdk>` (macOS), `-I` for the bundled ANTs sources,
  `inst/include`, and `CXX_STD=CXX17`.
- Link: `-Wl,-dead_strip -Wl,-x -Wl,-exported_symbol,_R_init_ANTsRCore`
  (macOS); `-Wl,--gc-sections -Wl,--version-script=ANTsRCore.map -Wl,-x
  -Wl,--strip-debug` (Linux); Windows: `-lws2_32 -lpsapi -lrpcrt4 -lgdi32
  -mwindows`, `-Wl,--allow-multiple-definition -Wl,--enable-auto-import
  -Wl,--enable-runtime-pseudo-reloc -Wl,--exclude-all-symbols`, plus
  `-Wl,--exclude-libs,ALL` and `-msse4.1 -mssse3` on x86 only.
- CMake options for ANTs (`-DBUILD_SHARED_LIBS=OFF`, `-DANTS_INSTALL_LIBS_ONLY=ON`, ...).

## R itself (`R CMD config`, `~/.R/Makevars`)
`CC`, `CXX`, `CXXFLAGS` (-O2 -g etc.), `SHLIB_*`. ANTsRCore only reads them.

## ANTsR
ANTsR contributes **no** flags of its own. It is a client of ANTsRCore: its
`src/Makevars` is untracked (gitignored) and only adds
`-I<ANTsRCore>/include`, `-I<ITKR>/libs/include/ITK-*` and links
`ANTsRCore/libs/lib/lib*.a` and `ITKR/libs/lib/lib*.a`. Anything affecting
the compiled ANTs/ITK code (optimisation, SSE, visibility, big-obj) is set here in ANTsRCore or in ITKR.
