# -----------------------------------------------------------------------------

TLOC_INCLUDE("/tl_base_ci/tl_base_ci.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})

# -----------------------------------------------------------------------------
# superbuild

set(PROJ_NAME "tl_window")
tl_add_superbuild(
  PROJ_NAME
    ${PROJ_NAME}
  DESTINATION
    "${CMAKE_SOURCE_DIR}/"
  )

# -----------------------------------------------------------------------------
# travis

set(TRAVIS_SCRIPT
"\
  - mkdir build
  - cd build
  - cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_INSTALL_PREFIX=../install -DTLOC_DETAILED_LOGS=ON ../
  - make install
  - cd ..
  - mkdir build_release
  - cd build_release
  - cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_INSTALL_PREFIX=../install -DTLOC_DETAILED_LOGS=ON ../
  - make install
"
)

tl_add_travis(
  LINUX_COMPILERS "clang-3.8;clang-4.0;clang-5.0"
  SCRIPT ${TRAVIS_SCRIPT}
  )

# -----------------------------------------------------------------------------
# gitignore

tl_add_gitignore(
  IGNORE_LIST "*setup*.sh"
  )

# -----------------------------------------------------------------------------
# ycm

tl_add_ycm_config()

# -----------------------------------------------------------------------------
# setup

tl_add_setup(
  NAME "setup"
  BUILD_DIR "build"
  BUILD_TYPE "Debug"
  DESTINATION ${SOURCE_DIR}
  CL_ARGS ${CL_ARGS}
  )

tl_add_setup(
  NAME "setup_release"
  BUILD_DIR "build_release"
  BUILD_TYPE "Release"
  DESTINATION ${SOURCE_DIR}
  CL_ARGS ${CL_ARGS}
  )

# -----------------------------------------------------------------------------
# project

add_subdirectory(${PROJ_NAME})

if (NOT TLOC_DISABLE_TESTS)
  add_subdirectory(${PROJ_NAME}_tests)
endif()
