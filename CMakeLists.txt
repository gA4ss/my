cmake_minimum_required (VERSION 3.5)
project(my VERSION 1.0)

# set(DEBUG 1)
if(DEBUG)
message(STATUS "compile debug version.")
add_definitions(-std=c++14 -g -O0 -DDEBUG -Wunused-variable)
else()
message(STATUS "compile release version.")
add_definitions(-std=c++14 -O3 -Wunused-variable)
endif(DEBUG)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

#
# Sub modules directories
#
set(SRC_DIRECTORY ./src)

#
# My include path
#
include_directories(
  ./
)

#
# System include path and link path
#
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

#
# My public header file
#
set(MY_PUBLIC_HEADERS 
  ${SRC_DIRECTORY}/my_common.h
  ${SRC_DIRECTORY}/my_compile.h
  ${SRC_DIRECTORY}/my_error.h
  ${SRC_DIRECTORY}/my_object.h
  ${SRC_DIRECTORY}/my_exception.h
  ${SRC_DIRECTORY}/my_log.h
  ${SRC_DIRECTORY}/my_debug.h
  ${SRC_DIRECTORY}/my_input.h
)

#
# Test Build
#
set(BUILD_TEST TRUE)
if(BUILD_TEST)
# add_executable(test_my_exception ${SRC_DIRECTORY}/test/test_my_exception.cc)
# target_link_libraries(test_my_exception my)
endif(BUILD_TEST)

#
# Library Build
#
add_library(${PROJECT_NAME} STATIC
  ${SRC_DIRECTORY}/my_common.cc
  ${SRC_DIRECTORY}/my_log.cc
  ${SRC_DIRECTORY}/my_object.cc
  ${SRC_DIRECTORY}/my_exception.cc
  ${SRC_DIRECTORY}/my_input.cc
  ${SRC_DIRECTORY}/my_debug.cc)
target_link_libraries(${PROJECT_NAME} uuid)

# set(RESEARCH TRUE)
# if(RESEARCH)
# message(STATUS "compile research codes.")
add_executable(test_regex test/test_regex.cc)
target_link_libraries(test_regex gtest pthread my)
add_executable(test_str test/test_str.cc)
target_link_libraries(test_str gtest pthread my)
add_executable(test_file test/test_file.cc)
target_link_libraries(test_file gtest pthread my)
add_executable(test_exception test/test_exception.cc)
target_link_libraries(test_exception my)

# endif(RESEARCH)

#
# Enable Test
#
#enable_testing()
#add_test(NAME test_misc_math COMMAND test_misc_math)
#set_tests_properties(test_misc_math PROPERTIES FAIL_REGULAR_EXPRESSION "failed")

#
# Install Set
#
INSTALL(TARGETS my ARCHIVE DESTINATION lib)
INSTALL(FILES ${MY_PUBLIC_HEADERS} DESTINATION include/my)
