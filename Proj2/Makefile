#This os our orignal generic makefile command that will build and stand along .cpp source
# Usage: e.g. make hello

.ccp :
	g++ -o $* $*.cpp -std=c++11

#This will build the two object files required for "poly_class_v2"
#and link them into a single exe
#Usage make -f makefile2 poly_class_v2





poly_class: Polynomial.o poly_class.o
		g++ -o $@ $@.o Polynomial.o -std=c++11


#This will buid the two object files rquired for "poly_class_v3"
# and line them into ta sing executable.
# Usage: make -f makefile3 poly_class_v3


# poly_class_v3: Polynomial.o poly_class_v2.o
#		g++ -o $@ $@.o Polynomial.o -std=c++11





poly_class.o : Polynomial.h
# poly_class_v2.o : Polynomial.h
Polynomial.o	: Polynomial.h

