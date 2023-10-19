# CMakeList.txt : CMake project for Day01_a, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Day03 "Day03.cpp" "Day03.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Day03 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
