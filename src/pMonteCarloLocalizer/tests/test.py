#!/usr/bin/env python3

import subprocess as sp
from numpy.random import random

# Compile program
print(sp.check_output(['g++', '-Wall', '-std=c++11', 'pf_test.cpp', '../ParticleFilter.cpp']))

# Test program. TODO: make inputs more realistic
x, y, z, θ, v, ω, d, dt = random((8,)) * 1000
args = list(map(str, [x, y, z, θ, v, ω, d, dt]))
print(sp.check_output(['./a.out'] + args))

# Cleanup.
sp.run(['rm', 'a.out'])

