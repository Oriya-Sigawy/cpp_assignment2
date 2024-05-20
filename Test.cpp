#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
/**
 * This function is used to check the result of the operator.
 * @param g the graph that the operator returned and needs to be checked
 * @param g_mat the expected matrix to check the graph with
 * @returns true if the g's adjacency matrix is equals to g_mat, false otherwise.
 */
bool check_result(ariel::Graph g, vector<vector<int>> g_mat)
{
    if (g.getNumOfVertices() != g_mat.size())
    {
        return false;
    }
    for (unsigned int i = 0; i < g.getNumOfVertices(); i++)
    {
        for (unsigned int j = 0; j < g.getNumOfVertices(); j++)
        {
            if (g.getAt(i, j) != g_mat[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(check_result(g3, expectedGraph));
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(check_result(g4, expectedGraph));
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Check onary plus")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = +g1;
    CHECK(check_result(g2, graph));
}

TEST_CASE("check operator +=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g2 += g1;
    vector<vector<int>> expected = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(check_result(g2, expected));
    ariel::Graph g3;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0},
        {1, 0, 2, 1},
        {1, 2, 0, 4},
        {1, 2, 3, 0}};
    g3.loadGraph(graph2);
    CHECK_THROWS(g3 += g2);
}
TEST_CASE("check minus with equal sizes")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    CHECK(check_result(g3, expectedGraph));
}
TEST_CASE("check minus with unequal sizes")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 - g6);
}
TEST_CASE("check operator -=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g2 -= g1;
    vector<vector<int>> expected = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 0}};
    CHECK(check_result(g2, expected));
    ariel::Graph g3;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0},
        {1, 0, 2, 1},
        {1, 2, 0, 4},
        {1, 2, 3, 0}};
    g3.loadGraph(graph2);
    CHECK_THROWS(g3 -= g2);
}
TEST_CASE("check /= with int")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 3, 6},
        {9, 0, 6},
        {3, 6, 0}};
    g1.loadGraph(graph);
    g1 /= 3;
    vector<vector<int>> expected = {
        {0, 1, 2},
        {3, 0, 2},
        {1, 2, 0}};
    CHECK(check_result(g1, expected));
}
TEST_CASE("check /= with double")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 4, 8},
        {9, 0, 7},
        {5, 7, 0}};
    g1.loadGraph(graph);
    g1 /= 3;
    vector<vector<int>> expected = {
        {0, 1, 2},
        {3, 0, 2},
        {1, 2, 0}};
    CHECK(check_result(g1, expected));
}
TEST_CASE("check /= with zero")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 3, 6},
        {9, 0, 6},
        {3, 6, 0}};
    g1.loadGraph(graph);
    CHECK_THROWS(g1 /= 0);
}
TEST_CASE("check *= with zero")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 3, 6},
        {9, 0, 6},
        {3, 6, 0}};
    g1.loadGraph(graph);
    g1 *= 0;
    vector<vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    CHECK(check_result(g1, expected));
}
TEST_CASE("check *=")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 3, 6},
        {9, 0, 6},
        {3, 6, 0}};
    g1.loadGraph(graph);
    g1 *= 5;
    vector<vector<int>> expected = {
        {0, 15, 30},
        {45, 0, 30},
        {15, 30, 0}};
    CHECK(check_result(g1, expected));
}
TEST_CASE("test postfix ++")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 3, 6},
        {9, 0, 6},
        {3, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1++;
    CHECK(check_result(g2, graph));
    vector<vector<int>> expected = {
        {0, 4, 7},
        {10, 0, 7},
        {4, 7, 0}};
    CHECK(check_result(g1, expected));
}
TEST_CASE("test prefix ++")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 3, 6},
        {9, 0, 6},
        {3, 6, 0}};
    g.loadGraph(graph);
    ++g;
    vector<vector<int>> expected = {
        {0, 4, 7},
        {10, 0, 7},
        {4, 7, 0}};
    CHECK(check_result(g, expected));
}
TEST_CASE("test postfix --")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 3, 6},
        {9, 0, 6},
        {3, 6, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1--;
    CHECK(check_result(g2, graph));
    vector<vector<int>> expected = {
        {0, 2, 5},
        {8, 0, 5},
        {2, 5, 0}};
    CHECK(check_result(g1, expected));
}
TEST_CASE("test prefix --")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 3, 6},
        {9, 0, 6},
        {3, 6, 0}};
    g.loadGraph(graph);
    --g;
    vector<vector<int>> expected = {
        {0, 2, 5},
        {8, 0, 5},
        {2, 5, 0}};
    CHECK(check_result(g, expected));
}

TEST_CASE("test > contains")
{
    vector<vector<int>> graph1 = {
        {0, 1},
        {2, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 3},
        {2, 0, 4},
        {-1, 3, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(g1 < g2);
    CHECK(g2 > g1);
}

TEST_CASE("test > more edges")
{
    vector<vector<int>> graph1 = {
        {0, 10},
        {7, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 5},
        {9, 0, 3},
        {2, -1, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(g1 < g2);
    CHECK(g2 > g1);
}

TEST_CASE("test > more vxs")
{
    vector<vector<int>> graph1 = {
        {0, 10},
        {7, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {9, 0, 3},
        {2, 0, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(g1 < g2);
    CHECK(g2 > g1);
}

TEST_CASE("test >=")
{
    vector<vector<int>> graph1 = {
        {0, 10},
        {7, 0}};
    vector<vector<int>> graph2 = {
        {0, 10},
        {7, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(g1 <= g2);
    CHECK(g2 >= g1);
}

TEST_CASE("test >=")
{
    vector<vector<int>> graph1 = {
        {0, 10},
        {7, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {9, 0, 3},
        {2, 0, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(!(g2 < g1));
    CHECK(g2 >= g1);
}

TEST_CASE("test == with non-big")
{
    vector<vector<int>> graph1 = {
        {0, 10},
        {7, 0}};
    vector<vector<int>> graph2 = {
        {0, 1},
        {9, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(!(g2 < g1));
    CHECK(!(g1 < g2));
    CHECK(g2 == g1);
}

TEST_CASE("test== with more edges")
{
    vector<vector<int>> graph1 = {
        {0, 10, 0},
        {7, 0, 0},
        {0, 0, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 5},
        {9, 0, 3},
        {2, -1, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(!(g1 == g2));
}

TEST_CASE("test== with equals mats")
{
    vector<vector<int>> graph1 = {
        {0, 10, 0},
        {7, 0, 0},
        {0, 0, 0}};
    vector<vector<int>> graph2 = {
        {0, 10, 0},
        {7, 0, 0},
        {0, 0, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK((g1 == g2));
}

TEST_CASE("test == with non equals")
{
    vector<vector<int>> graph1 = {
        {0, 10},
        {7, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {9, 0, 3},
        {2, 0, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(!(g2 == g1));
}

TEST_CASE("> with equals")
{
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {9, 0, 3},
        {2, 0, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {9, 0, 3},
        {2, 0, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK(!(g2 > g1));
    CHECK(!(g2 < g1));
}

TEST_CASE("> with empty graph")
{
    vector<vector<int>> graph1 = {
        {0}};
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {9, 0, 3},
        {2, 0, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK((g2 > g1));
}
TEST_CASE("> with smaller has more edges")
{
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {1, 5, 0}};
    vector<vector<int>> graph2 = {
        {0, 0, 1, 0},
        {9, 0, 3, 2},
        {2, 0, 0, 1},
        {0, 0, 0, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2.loadGraph(graph2);
    CHECK((g2 > g1));
}

TEST_CASE("check reference vs value")
{
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {1, 5, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);
    ariel::Graph g2;
    g2 = +g1;
    ++g1;
    vector<vector<int>> expected1 = {
        {0, 2, 3},
        {2, 0, 4},
        {2, 6, 0}};
    CHECK(check_result(g2, graph1));
    CHECK(check_result(g1, expected1));
    ariel::Graph g3;
    g3 = g1++;
    vector<vector<int>> expected2 = {
        {0, 3, 4},
        {3, 0, 5},
        {3, 7, 0}};
    CHECK(check_result(g3, expected1));
    CHECK(check_result(g1, expected2));
    g2 = ++g1;
    vector<vector<int>> expected3 = {
        {0, 4, 5},
        {4, 0, 6},
        {4, 8, 0}};
    CHECK(check_result(g2, expected3));
    g1 /= 2;
    vector<vector<int>> expected4 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 4, 0}};
    CHECK(check_result(g1, expected4));
    CHECK(check_result(g2, expected3));
}
