TLOC_INCLUDE("/tl_base_ci/tl_add_library.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})

tl_add_sdl(
  GIT_REPOSITORY "/home/samaursa/Repos/SDL-mirror"
  )

tl_add_library(
  LIB_NAME "tl_window"
  PUBLIC_HEADER_FILES "tl_window.h"
  SOURCE_FILES "tl_window.cpp"
  PUBLIC_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS}
  PUBLIC_LINK_LIBS "tl_base"
  )
