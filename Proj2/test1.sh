#!/bin/bash

clear
make -f Makefile poly_class

set -v

./poly_class << EOF
1
2 6
2
2 5 5
1
0 2
-3 6
EOF




