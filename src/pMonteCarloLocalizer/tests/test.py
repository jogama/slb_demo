#!/usr/bin/env python3

'''
builds and tests the particlefilter.
(may be better to build in a bash script, and call a python test from bash
(or actually, just do everything in bash and c++. Why am I generating the random inputs in python anyway, just to pass them to c++? ))

'''

import subprocess as sp
from os import chdir
from numpy.random import random

# Compile program
print('Cleaning!')
chdir('build')
sp.run(['rm', '-rf'])

print('\nBuilding!')
sp.run(['cmake', '..', '-Wno-dev'])
sp.run(['make']) # consider adding threads
chdir('..')

# Test program. TODO: make inputs more realistic
print('\nTesting!')
x, y, z, θ, v, ω, d, dt = random((8,)) * 1000
args = list(map(str, [x, y, z, θ, v, ω, d, dt]))
print(sp.check_output(['build/pf_test'] + args))
