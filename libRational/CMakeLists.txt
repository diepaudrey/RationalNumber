cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(rationalNumber)

# file to compile and name of the executable = ligne de ce qu'on va executer
add_executable(rationalNumber src/rational.cpp include/rational.hpp)

# include directory
target_include_directories(rationalNumber PRIVATE "include")

# compilation options
target_compile_features(rationalNumber PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(rationalNumber PRIVATE /W3)
else()
    target_compile_options(rationalNumber PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

