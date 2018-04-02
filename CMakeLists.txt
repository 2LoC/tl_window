# ---------------------------------
# auto-generated file, do not modify
# ----------------------------------

# -----------------------------------------------------------------------------

# You should not be modiying anything in this file. Instead, you should be
# using "include/CMakeLists.txt" file for your project where you will have
# access to tl_base_ci library

# -----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.11)

# -----------------------------------------------------------------------------

get_cmake_property(vars CACHE_VARIABLES)
foreach(var ${vars})
  get_property(currentHelpString CACHE "${var}" PROPERTY HELPSTRING)
	if("${currentHelpString}" MATCHES "No help, variable specified on the command line." OR "${currentHelpString}" STREQUAL "")
		list(APPEND CL_ARGS "-D${var}=${${var}}")
	endif()
endforeach()

# -----------------------------------------------------------------------------
# include helper

function(TLOC_INCLUDE_TEMP FILE PATHS)
  foreach(PATH ${PATHS})
    set(FULL_PATH ${PATH}/${FILE})
    if (EXISTS ${FULL_PATH})
      include(${FULL_PATH})
      return()
    endif()
  endforeach()
  message(FATAL_ERROR "Could not find file ${FILE} to include in paths ${PATHS}")
endfunction()

# -----------------------------------------------------------------------------

if(EXISTS "/home/samaursa/Repos/2LoC/tl_proj_template/CMakeLists_Pre.cmake")
  include("/home/samaursa/Repos/2LoC/tl_proj_template/CMakeLists_Pre.cmake")
endif()

# -----------------------------------------------------------------------------

include(FetchContent)

if (NOT TLOC_ALWAYS_FETCHCONTENT)
  find_package(tl_base_ci QUIET)
endif()

if(NOT tl_base_ci_FOUND OR TLOC_ALWAYS_FETCHCONTENT)
  message(STATUS "tl_base_ci NOT FOUND. Source will be downloaded.")

  set(FETCHCONTENT_QUIET OFF)

  FetchContent_Declare(tl_base_ci_ext
    GIT_REPOSITORY "https://github.com/2LoC/tl_base_ci"
    GIT_TAG "master"

    CMAKE_ARGS ${CL_ARGS}
  )

  FetchContent_GetProperties(tl_base_ci_ext)
  if(NOT tl_base_ci_POPULATED)
    FetchContent_Populate(tl_base_ci_ext)
    add_subdirectory(${tl_base_ci_ext_SOURCE_DIR} ${tl_base_ci_ext_BINARY_DIR})
    list(APPEND tl_base_ci_INCLUDE_DIRECTORIES "${tl_base_ci_ext_SOURCE_DIR}/include")
  endif()

else()
  message(STATUS "tl_base_ci FOUND: ${tl_base_ci_DIR}")
  get_target_property(tl_base_ci_INCLUDE_DIRECTORIES tl_base_ci INTERFACE_INCLUDE_DIRECTORIES)

endif()

# -----------------------------------------------------------------------------

TLOC_INCLUDE_TEMP("/tl_base_ci/tl_common.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})
TLOC_LOG_COMMON_VARIABLES()

# -----------------------------------------------------------------------------

# get the current directory name, which will be this project's external
# build name
string(REPLACE "/" ";" PATH_LIST "${CMAKE_SOURCE_DIR}")
list(REVERSE PATH_LIST)
list(GET PATH_LIST 0 PROJ_NAME)

# -----------------------------------------------------------------------------

if(NOT TLOC_DISABLE_TESTS)
  enable_testing()
endif()

project(${PROJ_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD ${TLOC_CMAKE_CXX_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED ${TLOC_CMAKE_CXX_STANDARD_REQUIRED})

# -----------------------------------------------------------------------------

if(EXISTS "/home/samaursa/Repos/2LoC/tl_proj_template/CMakeLists_Post.cmake")
  include("/home/samaursa/Repos/2LoC/tl_proj_template/CMakeLists_Post.cmake")
endif()

# -----------------------------------------------------------------------------

add_subdirectory(include/)

# -----------------------------------------------------------------------------
