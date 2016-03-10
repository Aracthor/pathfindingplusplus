cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("pathfindingplusplus")

if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
 set(warnings "-Wall -Wextra -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(warnings "/W4 /WX /EHsc")
endif()

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  message(STATUS "Your compiler (${CMAKE_CXX_COMPILER}) has no C++11 support. Please use a better C++ compiler.")
endif()


include_directories(inc/)

set(SRCS_DIR srcs)
set(SRCS)
add_subdirectory(${SRCS_DIR})
foreach(file ${SRCS_FILES})
  set(SRCS ${SRCS} ${SRCS_DIR}/${file})
endforeach()

add_executable(pathfindingplusplus ${SRCS})
