#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> color, d, parent;

void BFS(int s)
{
    queue<int> Q;
    color[s] = 1; // GRAY
    d[s] = 0;
    parent[s] = -1;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : adj[u])
        {
            if (color[v] == 0) // WHITE
            {
                color[v] = 1; // GRAY
                d[v] = d[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
        color[u] = 2; // BLACK
    }
}

int main()
{
    int vertex = 8;
    adj.resize(vertex);
    adj[0] = {1, 4};
    adj[1] = {5, 0};
    adj[5] = {1, 2, 6};
    adj[2] = {5, 3};
    adj[6] = {5, 7};
    adj[4] = {0};
    adj[3] = {2};
    adj[7] = {6};
    color.assign(vertex, 0);
    d.assign(vertex, -1);
    parent.assign(vertex, -1);
    int source = 1;
    BFS(source);
}