cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(myExamples)

# file to compile and name of the executable = ligne de ce qu'on va executer
add_executable(myExamples src/rationalTest.cpp include/rationalTest.hpp)

# include directory
target_include_directories(myExamples PRIVATE "include")

# compilation options
target_compile_features(myExamples PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(myExamples PRIVATE /W3)
else()
    target_compile_options(myExamples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

