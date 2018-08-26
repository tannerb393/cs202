#!/bin/bash

clear
make matrix_math

set -v

./matrix_math -add A B -out X<< EOF 
EOF

./matrix_math -sub A B -out Y<< EOF 
EOF

./matrix_math -mul G H -out Z<< EOF 
EOF
