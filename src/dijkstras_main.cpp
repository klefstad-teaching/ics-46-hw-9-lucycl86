#include "dijkstras.h"

void test_dijkstras()
{
    Graph G;
    file_to_graph("src/small.txt", G);
    vector<int> previous(G.size(), -1);
    vector<int> d = dijkstra_shortest_path(G, 0, previous);
    print_path(d, 0);
}

int main()
{
    test_dijkstras();
    return 0;
}