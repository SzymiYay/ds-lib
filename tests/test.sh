#!/bin/bash
gcc ../src/dynamic_array.c test.c -o test.out && ./test.out && rm -rf *.out