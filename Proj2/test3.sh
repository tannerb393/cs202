#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
3
1 -2 6 15
4
6 4 8 1 8 
1
0 0
6 10
EOF





