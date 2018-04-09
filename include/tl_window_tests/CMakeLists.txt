# -----------------------------------------------------------------------------

set(EXE_NAME "tl_window_tests")

# -----------------------------------------------------------------------------

set(${EXE_NAME}_SOURCE_FILES
  "main.cpp"
  )

tl_add_tl_base()
tl_add_fmt()
tl_add_sdl(GIT_REPOSITORY "/home/samaursa/Repos/SDL-mirror")

# -----------------------------------------------------------------------------

tl_add_executable(
  EXE_NAME
    ${EXE_NAME}
  SOURCE_FILES
    ${${EXE_NAME}_SOURCE_FILES}
  BUILD_INTERFACE
    ${CMAKE_SOURCE_DIR}/include/
  LINK_LIBS
    "tl_window;tl_base;SDL2;fmt"

  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  )

add_test(NAME ${EXE_NAME} COMMAND ${EXE_NAME})

# -----------------------------------------------------------------------------
