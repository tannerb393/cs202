#This os our orignal generic makefile command that will build and stand along .cpp source
# Usage: e.g. make hello

.ccp:
	g++ -o $* $*.cpp -std=c++11

#This will build the two object files required for 
#and link them into a single exe
#Usage make  matrix_test





matrix_math: Matrix.o matrix_math.o
		g++ -o $@ $@.o Matrix.o -std=c++11

#matrix_test2: Matrix.o matrix_test2.o
#		g++ -o $@ $@.o Matrix.o -std=c++11


# This will build the two objects files required for the matrix_test
# which are dependent on Matrix.h


%.o : %.cpp Matrix.h
	g++ -c $< -std=c++11




matrix_math.o : Matrix.h
Matrix.o	: Matrix.h

