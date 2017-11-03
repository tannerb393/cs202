#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
5
4 3 -2 1 6 0
6
-6 2 -2 2 11 7 4
1
3 5
0 8
EOF





