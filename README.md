# System Programming 2 Assignment 1

In this assignment I extended Graph. 
As requested, I added comparison and arithmetic operators to Graph, each operator has a declaration in Graph.hpp and an implementation in Graph.cpp.  
* `g1+g2`: returns a graph with adjacency_matrix that was obtained by adding g1's adjacency_matrix to g2's adjacency_matrix.
* `+g1`: unary plus - returns a deep copy of g1.
* `g1+=g2`: returns a reference to g1 after adding g2's adjacency_matrix to g1's adjacency_matrix.
* `g1-g2`: returns a graph with adjacency_matrix that was obtained by subtracting g2's adjacency_matrix from g1's adjacency_matrix.
* `-g1`: unary minus - returns a graph with adjacency_matrix that was obtained by multiplying g1's adjacency_matrix with -1. 
* `g1-=g2`: returns a reference to g1 after subtracting g2's adjacency_matrix from g1's adjacency_matrix.
* `g1*g2`: returns a graph with adjacency_matrix that was obtained by multiplying g2's adjacency_matrix with g1's adjacency_matrix.
* `g1*=x`: multiplying with scalar - returns a reference to g1 after multiplying g1's adjacency_matrix with x.
* `g1/=x`: dividing by scalar - returns a reference to g1 after dividing g1's adjacency_matrix by x. The function also checks that x is not zero.
* `++g1`: prefix increment - first the function increases g1's adjacency_matrix by 1 and than the function returns a reference to g1.
* `--g1`: prefix decrement - first the function decreases g1's adjacency_matrix by 1 and than the function returns a reference to g1.
* `g1++`: postfix increment - the function creates a deep copy of g1, then increases g1's adjacency_matrix by 1 and than the function returns the deep copy.
* `g1--`: postfix decrement - the function creates a deep copy of g1, then decreases g1's adjacency_matrix by 1 and than the function returns the deep copy.
* 
