#--------------------------------------------------------
# The CMakeLists.txt for:                       pMonteCarloLocalizer
# Author(s):                              
#--------------------------------------------------------

SET(SRC
  ParticleFilter.cpp
  MonteCarloLocalizer.cpp
  MonteCarloLocalizer_Info.cpp
  main.cpp
)

ADD_SUBDIRECTORY(range_libc)

ADD_EXECUTABLE(pMonteCarloLocalizer ${SRC})

TARGET_LINK_LIBRARIES(pMonteCarloLocalizer
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

SET(CMAKE_CXX_FLAGS "-std=c++11")
