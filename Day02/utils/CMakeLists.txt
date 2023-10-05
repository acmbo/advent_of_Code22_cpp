# CMakeList.txt : CMake project for utils, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library(Utils utils.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Utils PROPERTY CXX_STANDARD 20)
endif()

