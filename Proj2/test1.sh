#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
2
2 2 1
2
2 2 2
5
0 5
3 6
EOF




