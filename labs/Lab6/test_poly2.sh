#!/bin/bash

clear
make -f makefile2 poly_class_v2

set -v

./poly_class_v2 << EOF
2
3 -2 1
2
2 2 2
EOF

./poly_class_v2 << EOF
2
1 2 3
3
1 2 3 4
EOF



