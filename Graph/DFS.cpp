#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> color, d, f, parent;
int timer;

void DFS_visit(int u)
{
    color[u] = 1;   // GRAY
    d[u] = ++timer; // discovery time

    for (int v : adj[u])
    {
        if (color[v] == 0) // WHITE
        {
            parent[v] = u;
            DFS_visit(v); // go deeper
        }
    }
    color[u] = 2;   // BLACK
    f[u] = ++timer; // finishing time
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
    d.resize(vertex);
    f.resize(vertex);
    parent.assign(vertex, -1);
    timer = 0;
    for (int i = 0; i < vertex; i++)
    {
        if (color[i] == 0)
        {
            DFS_visit(i);
        }
    }
}