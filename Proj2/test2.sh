#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
2
1 2 3
3
1 2 3 4
EOF



