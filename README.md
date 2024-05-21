//214984932 Oriyas.07@gmail.com
# System Programming 2 Assignment 2

In this assignment I extended the class "Graph".   
As requested, I added comparison and arithmetic operators to Graph, each operator has a declaration in Graph.hpp and an implementation in Graph.cpp.  
`Aritmethic operators`:  
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

  `Comparison operators`:
  
* `g1>g2`: checks if g1's adjacency_matrix contains g2's adjacency_matrix. If not, checks if g1 has more edges than g2. If g1 and g2 have the same number of edges, checks if g1 has more vertices than g2.
  If one of the conditions is true, returns true. Else, returns false.
* `g1>=g2`: checks if g1 is bigger or equal to g2 (by calling to > and ==). If it is, returns true. Else, returns false.
* `g1<g2`: checks if g2 is bigger than g1 (by calling to >). If it is, returns true. Else, returns false.
* `g1<=g2`: checks if g1 is smaller or equal to g2 (by calling < and ==). If it is, returns true. Else, returns false.
* `g1==g2`: checks if g1 is not bigger than g2 and g2 is not bigger than g1. In that case, returns true. Else, checks that g1's adjacency_matrix is equal to g2's adjacency_matrix. If the matrixes are equals, returns true. Else, returns false.
* `g1!=g2`: returns the negation of g1==g2.

I don't see how the operators affects the Algorithms.
