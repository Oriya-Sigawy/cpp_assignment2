// 214984932 Oriyas.07@gmail.com

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Graph.hpp"

using std::vector;

namespace ariel
{
    Graph::Graph()
    {
        // defult
        this->vertices = 5;
        this->adjacency_matrix = vector<vector<int>>(5, vector<int>(5, 0));
        this->edges = 0;
        this->directed = false;
    }

    void Graph::loadGraph(vector<vector<int>> g)
    {
        // reset
        this->vertices = 0;
        this->edges = 0;

        this->vertices = g.size();                  // set num of vertices
        for (unsigned int i = 0; i < vertices; i++) // this loop checks that there is enough values in every raw of the matrix
        {
            if (g[i].size() != vertices)
            {
                throw std::invalid_argument("this is not a square matrix");
            }
        }
        this->adjacency_matrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
        for (unsigned int i = 0; i < vertices; i++) // copy the matrix
        {
            adjacency_matrix[i] = g[i];
        }
        for (unsigned int i = 0; i < vertices; i++) // calculates number of edges in a graph
        {
            for (unsigned int j = 0; j < vertices; j++)
            {
                if (adjacency_matrix[i][j] != 0)
                {
                    this->edges++;
                }
            }
        }
        this->directed = checkDirected(); // check if the graph is connected
        if (!directed)
        {
            edges /= 2;
        }
    }

    // getters
    unsigned int Graph::getNumOfVertices() const
    {
        return this->vertices;
    }
    int Graph::getAt(unsigned int x, unsigned int y) const
    {
        if (x >= this->vertices || y >= this->vertices)
        {
            throw std::out_of_range("");
        }
        return this->adjacency_matrix[x][y];
    }
    unsigned int Graph::getNumOfEdges() const
    {
        return this->edges;
    }
    bool Graph::isDirected() const
    {
        return this->directed;
    }

    std::string Graph::to_string() const
    {
        string graph_to_string = "";
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            graph_to_string += "[" + std::to_string(this->adjacency_matrix[i][0]);
            for (unsigned int j = 1; j < this->vertices; j++)
            {
                graph_to_string += ", " + std::to_string(this->adjacency_matrix[i][j]);
            }
            graph_to_string += "]\n";
        }
        return graph_to_string;
        // std::string str_v = std::to_string(this->vertices);
        // std::string str_e = std::to_string(this->edges);
        // return "Graph with " + str_v + " vertices and " + str_e + " edges.";
    }

    bool Graph::checkDirected()
    {
        bool ans = false;
        for (unsigned int i = 0; i < vertices; i++)
        {
            for (unsigned int j = 0; j < vertices; j++)
            {
                if (adjacency_matrix[i][j] != adjacency_matrix[j][i])
                {
                    ans = true;
                    break;
                }
            }
            if (ans)
            {
                break;
            }
        }
        return ans;
    }

    //////////////////////////
    bool areEqualSize(Graph g1, Graph g2)
    {
        return (g1.getNumOfVertices() == g2.getNumOfVertices());
    }
    Graph operator+(const Graph &g1, const Graph &g2)
    {
        if (!areEqualSize(g1, g2))
        {
            throw std::invalid_argument("");
        }
        unsigned int v = g1.getNumOfVertices();
        vector<vector<int>> g3_matrix = vector<vector<int>>(v, vector<int>(v, 0));
        for (unsigned int i = 0; i < v; i++)
        {
            for (unsigned int j = 0; j < v; j++)
            {
                g3_matrix[i][j] = g1.getAt(i, j) + g2.getAt(i, j);
            }
        }
        Graph g3;
        g3.loadGraph(g3_matrix);
        return g3;
    }
    Graph Graph::operator+() const
    { // returns a copy of the same graph
        vector<vector<int>> g3_matrix = vector<vector<int>>(this->vertices, vector<int>(this->vertices, 0));
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                g3_matrix[i][j] = this->adjacency_matrix[i][j];
            }
        }
        Graph g3;
        g3.loadGraph(g3_matrix);
        return g3;
    }
    Graph &Graph::operator+=(const Graph &g2)
    {
        if (!areEqualSize(*this, g2))
        {
            throw std::invalid_argument("");
        }
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                this->adjacency_matrix[i][j] = this->adjacency_matrix[i][j] + g2.getAt(i, j);
            }
        }
        return *this;
    }

    Graph operator-(const Graph &g1, const Graph &g2)
    {
        if (!areEqualSize(g1, g2))
        {
            throw std::invalid_argument("");
        }
        unsigned int v = g1.getNumOfVertices();
        vector<vector<int>> g3_matrix = vector<vector<int>>(v, vector<int>(v, 0));
        for (unsigned int i = 0; i < v; i++)
        {
            for (unsigned int j = 0; j < v; j++)
            {
                g3_matrix[i][j] = g1.getAt(i, j) - g2.getAt(i, j);
            }
        }
        Graph g3;
        g3.loadGraph(g3_matrix);
        return g3;
    }

    Graph Graph::operator-() const
    {
        vector<vector<int>> g3_matrix = vector<vector<int>>(this->vertices, vector<int>(this->vertices, 0));
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                g3_matrix[i][j] = (-1) * this->adjacency_matrix[i][j];
            }
        }
        Graph g3;
        g3.loadGraph(g3_matrix);
        return g3;
    }
    Graph &Graph::operator-=(const Graph &g2)
    {
        if (!areEqualSize(*this, g2))
        {
            throw std::invalid_argument("");
        }
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                this->adjacency_matrix[i][j] = this->adjacency_matrix[i][j] - g2.getAt(i, j);
            }
        }
        return *this;
    }

    bool Graph::operator>(const Graph &g2) const
    {
        if (this->vertices != g2.getNumOfVertices())
        {
            bool contains = true;
            for (unsigned int i = 0; i < this->vertices; i++) // check if this contains g2
            {
                for (unsigned int j = 0; j < this->vertices; j++)
                {
                    if (this->adjacency_matrix[i][j] == g2.getAt(0, 0))
                    {
                        contains = true;
                        for (unsigned int k = 0; k < g2.getNumOfVertices(); k++)
                        {
                            for (unsigned int l = 0; l < g2.getNumOfVertices(); l++)
                            {
                                if (i + k >= this->vertices || j + l >= this->vertices)
                                {
                                    contains = false;
                                    break;
                                }
                                if (this->adjacency_matrix[i + k][j + l] != g2.getAt(k, l))
                                {
                                    contains = false;
                                    break;
                                }
                            }
                            if (!contains)
                            {
                                break;
                            }
                        }
                        if (contains)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        if (this->edges > g2.getNumOfEdges())
        {
            return true;
        }
        if (this->edges == g2.getNumOfEdges() && this->vertices > g2.getNumOfVertices())
        {
            return true;
        }
        return false;
    }

    bool Graph::operator>=(const Graph &g2) const
    {
        return ((*this == g2) || (*this > g2));
    }

    bool Graph::operator<(const Graph &g2) const
    {
        return (g2 > *this);
    }

    bool Graph::operator<=(const Graph &g2) const
    {
        return ((*this == g2) || *this < g2);
    }

    bool Graph::operator==(const Graph &g2) const
    {
        if (!(*this > g2) && !(g2 > *this))
        {
            return true;
        }
        if (this->vertices != g2.getNumOfVertices())
        {
            return false;
        }
        for (unsigned int i = 0; i < this->vertices; i++) // compare the graph's matrixes
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                if (this->adjacency_matrix[i][j] != g2.getAt(i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool Graph::operator!=(const Graph &g2) const
    {
        return (!(*this == g2));
    }

    Graph &Graph::operator*=(int x)
    {
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                this->adjacency_matrix[i][j] *= x;
            }
        }
        return *this;
    }

    Graph &Graph::operator/=(int x)
    {
        if (x == 0)
        {
            throw std::invalid_argument("Can't devide by zero");
        }
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                this->adjacency_matrix[i][j] /= x;
            }
        }
        return *this;
    }

    Graph operator*(const Graph &g1, const Graph &g2)
    {
        if (!areEqualSize(g1, g2))
        {
            throw std::invalid_argument("");
        }
        unsigned int v = g1.getNumOfVertices();
        vector<vector<int>> g3_matrix = vector<vector<int>>(v, vector<int>(v, 0));
        for (unsigned int i = 0; i < v; i++)
        {
            for (unsigned int j = 0; j < v; j++)
            {
                for (unsigned int k = 0; k < v; k++)
                {
                    if (i == j) // the main diagonal should be zeros in a legal graph
                    {
                        g3_matrix[i][j] = 0;
                    }
                    else
                    {
                        g3_matrix[i][j] += g1.getAt(i, k) * g2.getAt(k, j);
                    }
                }
            }
        }
        Graph g3;
        g3.loadGraph(g3_matrix);
        return g3;
    }
    // g++
    Graph Graph::operator++(int)
    {
        // returns a copy of this and than increase its edges by 1
        vector<vector<int>> g3_matrix = vector<vector<int>>(this->vertices, vector<int>(this->vertices, 0));
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                if (this->adjacency_matrix[i][j] != 0)
                {
                    g3_matrix[i][j] = this->adjacency_matrix[i][j];
                    this->adjacency_matrix[i][j] += 1;
                }
            }
        }
        Graph g3;
        g3.loadGraph(g3_matrix);
        return g3;
    }
    // g--
    Graph Graph::operator--(int)
    {
        // returns a copy of this and than decrease its edges by 1
        vector<vector<int>> g3_matrix = vector<vector<int>>(this->vertices, vector<int>(this->vertices, 0));
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                if (this->adjacency_matrix[i][j] != 0)
                {
                    g3_matrix[i][j] = this->adjacency_matrix[i][j];
                    this->adjacency_matrix[i][j] -= 1;
                }
            }
        }
        Graph g3;
        g3.loadGraph(g3_matrix);
        return g3;
    }
    //++g
    Graph &Graph::operator++()
    {
        // first increase the edges by 1 and than returns this
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                if (this->adjacency_matrix[i][j] != 0)
                {
                    this->adjacency_matrix[i][j] += 1;
                }
            }
        }
        return *this;
    }
    //--g
    Graph &Graph::operator--()
    {
        // first decrease the edges by 1 and than returns this
        for (unsigned int i = 0; i < this->vertices; i++)
        {
            for (unsigned int j = 0; j < this->vertices; j++)
            {
                if (this->adjacency_matrix[i][j] != 0)
                    this->adjacency_matrix[i][j] -= 1;
            }
        }
        return *this;
    }

    // cout (<<)
    ostream &operator<<(ostream &os, const Graph &g1)
    {
        os << "Adjacency Matrix of the Graph:\n";
        os << g1.to_string();
        return os;
    }

}
