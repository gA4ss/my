cmake_minimum_required (VERSION 3.5)
project(my VERSION 1.0)

# -g -O0 allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11 -O3)
#add_definitions(-std=c++11 -g -O0)

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
  ./src
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
  ${SRC_DIRECTORY}/my_exception.h
  ${SRC_DIRECTORY}/my_log.h
  ${SRC_DIRECTORY}/my_uuid.h
  ${SRC_DIRECTORY}/my_object.h
  ${SRC_DIRECTORY}/my_type.h
)

#
# Test Build
#
set(BUILD_TEST TRUE)
if(BUILD_TEST)
add_executable(test_my_uuid ${SRC_DIRECTORY}/test_my_uuid.cc ${SRC_DIRECTORY}/my_uuid.cc)
target_link_libraries(test_my_uuid uuid)
add_executable(test_my_exception ${SRC_DIRECTORY}/test_my_exception.cc)
target_link_libraries(test_my_exception my)
endif(BUILD_TEST)

#
# Library Build
#
add_library(${PROJECT_NAME} STATIC
  ${SRC_DIRECTORY}/my_common.cc
  ${SRC_DIRECTORY}/my_log.cc
  ${SRC_DIRECTORY}/my_exception.cc
  ${SRC_DIRECTORY}/my_uuid.cc)
target_link_libraries(${PROJECT_NAME} uuid)

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
