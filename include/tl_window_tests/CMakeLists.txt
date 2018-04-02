# -----------------------------------------------------------------------------

set(EXE_NAME "tl_window_tests")

# -----------------------------------------------------------------------------

set(${EXE_NAME}_SOURCE_FILES
  "main.cpp"
  )

# -----------------------------------------------------------------------------

tl_add_executable(
  EXE_NAME
    ${EXE_NAME}
  SOURCE_FILES
    ${${EXE_NAME}_SOURCE_FILES}
  BUILD_INTERFACE
    ${CMAKE_SOURCE_DIR}/include/
  )

add_test(NAME ${EXE_NAME} COMMAND ${EXE_NAME})

# -----------------------------------------------------------------------------
