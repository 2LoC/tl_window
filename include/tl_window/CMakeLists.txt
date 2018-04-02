TLOC_INCLUDE("/tl_base_ci/tl_add_library.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})

tl_add_library(
  LIB_NAME "tl_window"
  PUBLIC_HEADER_FILES "tl_window.h"
  SOURCE_FILES "tl_window.cpp"
  )
