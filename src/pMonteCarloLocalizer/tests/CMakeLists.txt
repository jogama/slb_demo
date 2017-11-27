#--------------------------------------------------------
# The CMakeLists.txt for:            pf_test
# Author(s):                              
#--------------------------------------------------------

INCLUDE_DIRECTORIES(..)
INCLUDE_DIRECTORIES(../range_libc)

SET(SRC
  pf_test.cpp
  ../ParticleFilter.cpp
  ../range_libc/includes/RangeLib.h
  ../range_libc/vendor/lodepng/lodepng.h
)

ADD_EXECUTABLE(pf_test ${SRC})

SET(CMAKE_CXX_FLAGS "-std=c++11")# "-Wall" "-Wextra")
