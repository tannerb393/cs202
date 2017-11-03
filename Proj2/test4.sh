#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
4
3 -2 1 6 0
5
2 -2 2 11 7 4
3
-3 5
-1 8
EOF





