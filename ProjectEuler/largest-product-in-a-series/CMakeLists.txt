get_filename_component(exercise ${CMAKE_CURRENT_SOURCE_DIR} NAME)
cmake_minimum_required(VERSION 2.8.11)
project(${exercise} CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework date_time regex)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

if(${EXERCISM_RUN_ALL_TESTS})
    add_definitions(-DEXERCISM_RUN_ALL_TESTS)
endif()

string(REPLACE "-" "_" file ${exercise})

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
    set(exercise_cpp ${file}.cpp)
else()
    set(exercise_cpp "")
endif()

add_executable(${exercise} ${file}_test.cpp ${exercise_cpp} ${file}.h)
target_include_directories(${exercise} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${exercise} ${Boost_LIBRARIES})

add_custom_command(TARGET ${exercise} POST_BUILD COMMAND ${exercise})
