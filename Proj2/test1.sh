#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
2
3 -2 1
2
2 2 2
EOF




