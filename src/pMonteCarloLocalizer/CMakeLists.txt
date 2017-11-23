#--------------------------------------------------------
# The CMakeLists.txt for:                       pMonteCarloLocalizer
# Author(s):                              
#--------------------------------------------------------

SET(SRC
  MonteCarloLocalizer.cpp
  MonteCarloLocalizer_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pMonteCarloLocalizer ${SRC})

TARGET_LINK_LIBRARIES(pMonteCarloLocalizer
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

