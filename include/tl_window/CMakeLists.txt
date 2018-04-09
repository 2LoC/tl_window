TLOC_INCLUDE("/tl_base_ci/tl_add_library.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})

tl_add_sdl()
tl_add_tl_base()
tl_add_fmt()

tl_add_library(
  LIB_NAME
    "tl_window"
  PUBLIC_HEADER_FILES
    "tl_window.h"
  SOURCE_FILES
    "tl_window.cpp"
  PUBLIC_INCLUDE_DIRS
    ${SDL2_INCLUDE_DIRS} ${FMT_INCLUDE_DIRS}
  PUBLIC_LINK_LIBS
    "tl_base"

  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  )
