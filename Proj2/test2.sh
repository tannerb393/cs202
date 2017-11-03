#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
2
1 2 3
3
3 2 0 1
11
0 3
2 11
EOF



