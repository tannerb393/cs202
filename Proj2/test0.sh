#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
0
5
1
2 5
4
0 5
3 6
EOF




