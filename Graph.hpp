// 214984932 Oriyas.07@gmail.com

// TODO-&
/*
this class represents a graph.
*/
#pragma once

#include <vector>
#include <string>
#include <iostream>
using std::ostream;
using std::string;
using std::vector;

namespace ariel
{
    class Graph
    {
    private:
        // the graph's fields:
        vector<vector<int>> adjacency_matrix;
        unsigned int vertices;
        unsigned int edges;
        bool directed;

        /*
        this method checks if the graph is directed by the adjacency matrix -
        if the matrix is simetrical, the graph is undirected.
        otherwise, the graph is directed.
        @returns: true if the graph is directed, false if the graph is undirected.*/
        bool checkDirected();

        /**
         * This metod is an helper function to check if 2 graphs have the same number of vertices.
         * @param g1 the first graph to check
         * @param g2 the second graph to check
         * @returns true if g1, g2 have the same number of vertices, false otherwise.
         */
        friend bool areEqualSize(Graph g1, Graph g2);

    public:
        /*
        this is a defult constructor.
        the constructor initializes the graph's fields to the following variables:
        directed -> false
        vertices -> 5
        edges -> 0
        adjacency matrix -> matrix of zeros in size 5x5
        */
        Graph();

        /*
        this method used to load a matrix to the graph.
        the func initializes the graph's fields.
        */
        void loadGraph(vector<vector<int>> g);

        /*
        this method creates a string in the format:
        "Graph with <num of vertices> vertices and <num of edges> edges."
        @returns: the string that represents the graph.
        */
        string to_string() const;

        // getters:
        unsigned int getNumOfVertices() const;
        int getAt(unsigned int x, unsigned int y) const;
        unsigned int getNumOfEdges() const;
        bool isDirected() const;

        // Aritmetic operators
        friend Graph operator+(const Graph &g1, const Graph &g2); // plus
        Graph operator+() const;                                        // unary plus
        Graph &operator+=(const Graph &g2);                       // plus equal
        friend Graph operator-(const Graph &g1, const Graph &g2); // minus
        Graph operator-() const;                                        // unary minus
        Graph &operator-=(const Graph &g2);                       // minus equal

        // comparison operators
        bool operator>(const Graph &g2) const; // bigger
        bool operator>=(const Graph &g2) const;      // bigger or equal
        bool operator<(const Graph &g2) const;       // smaller
        bool operator<=(const Graph &g2) const;      // smaller or equal
        bool operator==(const Graph &g2) const;      // equal
        bool operator!=(const Graph &g2) const;      // not equal

        Graph &operator*=(int x);                                 // mul with scalar
        Graph &operator/=(int x);                                 // dev with scalar
        friend Graph operator*(const Graph &g1, const Graph &g2); // mul with another graph

        Graph operator++(int); // g++
        Graph operator--(int); // g--
        Graph &operator++();   //++g
        Graph &operator--();   //--g

        // cout (<<)
        friend ostream &operator<<(ostream &os, const Graph &g1);
    };
}
