# set cmake requirements and then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# when makefiles are generated, output all command lines by default 
# this also can be done by removing set command
# and running cmake with "make VERBOSE=1"
set(CMAKE_VERBOSE_MAKEFILE ON)

# set the C++ standard to be used
set(CMAKE_CXX_STANDARD 14)

# declare the build of mpags-cipher main program
add_executable(mpags-cipher 
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    MPAGSCipher/ProcessCommandLine.cpp
    )

target_include_directories(mpags-cipher
  PRIVATE MPAGSCipher)

# set compiler flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)