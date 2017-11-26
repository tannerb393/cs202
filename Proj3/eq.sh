#!/bin/bash

clear
make matrix_math

set -v

./matrix_math -eq A B << EOF 
EOF

./matrix_math -eq A A << EOF 
EOF



