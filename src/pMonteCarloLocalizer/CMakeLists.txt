#--------------------------------------------------------
# The CMakeLists.txt for:            pMonteCarloLocalizer
# Author(s):                              
#--------------------------------------------------------

INCLUDE_DIRECTORIES(range_libc)

SET(SRC
  ParticleFilter.cpp
  MonteCarloLocalizer.cpp
  MonteCarloLocalizer_Info.cpp
  main.cpp
  range_libc/includes/RangeLib.h
  range_libc/vendor/lodepng/lodepng.h
)

ADD_EXECUTABLE(pMonteCarloLocalizer ${SRC})

TARGET_LINK_LIBRARIES(pMonteCarloLocalizer
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

SET(CMAKE_CXX_FLAGS "-std=c++11")
