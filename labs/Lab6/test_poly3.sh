#!/bin/bash

clear
make -f makefile3 poly_class_v3

set -v

./poly_class_v3 << EOF
2
3 -2 1
2
2 2 2
EOF

./poly_class_v3 << EOF
2
1 2 3
3
1 2 3 4
EOF



