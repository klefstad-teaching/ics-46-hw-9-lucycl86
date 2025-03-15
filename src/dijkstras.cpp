#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int numVertices = G.size();
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    minheap.push({0, source});
    while(!minheap.empty())
    {
        int u = minheap.top().second;
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
                minheap.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int> path;
    stack<int> s;
    for(int i = destination; i != -1; i = previous[i])
        s.push(i);
    while(!s.empty())
    {
        path.push_back(s.top());
        s.pop();
    }
    return path;
}

void print_path(const vector<int>& v, int total)
{
    for(size_t i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n";
    cout << "Total cost is " << total << endl;
}