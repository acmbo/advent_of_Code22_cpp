﻿# CMakeList.txt : CMake project for Day01_a, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Day05 "Day05.cpp" "Day05.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Day05 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
