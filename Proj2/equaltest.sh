#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
2
3 2 1
2
3 2 1
30
0 4
11 12
EOF





