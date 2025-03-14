#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap; // <vertex, weight>
    minheap.push({source, 0});
    while(!minheap.empty())
    {
        int u = minheap.top().first;
        minheap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(Edge e: G[u])
        {
            int v = e.dst;
            int weight = e.weight;
            if(!visited[v] && distances[u] + weight< distances[v])
            {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minheap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int> path;
    for(int i = destination; i != -1; i = previous[i])
        path.push_back(i);
    return path;
}

void print_path(const vector<int>& v, int total)
{
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n";
    cout << "Total cost: " << total << endl;
}