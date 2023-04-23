#!/usr/bin/python3
import math

samples_per_second = 22050
uint16_max = 32767


with open("./out.csv", 'w') as outfile:
    for i in range(samples_per_second):
        rad = i * 2 * math.pi / samples_per_second
        sin = math.sin(rad)
        expanded = round(sin * uint16_max)

        outfile.write(hex(expanded) + ", ")