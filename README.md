# Demo for SLB

## Goals
Given a map, vehicles can localize themselves using a monte-carlo localization moos app we'll make here.

The map will be computer generated, probably a CSV from python with documentation to visualize using matplotlib, blender, or MORSE. Once this works, we can get real data from data.shom.fr and test with that.

A compass and simple sonar will be simulated. 

## How to build
1. Make sure you've installed MOOS-IvP  
2. run `./build.sh`

## Thanks 
Thanks go out to the [MIT RACECAR folk](https://github.com/mit-racecar) for their [particle filter code](https://github.com/mit-racecar/particle_filter). Our localizer is based off of this one. 
