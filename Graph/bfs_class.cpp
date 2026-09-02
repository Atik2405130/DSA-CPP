#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    // Number vertices as:
    // 0=r, 1=s, 2=t, 3=u, 4=v, 5=w, 6=x, 7=y

    int vertex = 8;
    vector<vector<int>> adj(vertex);

    // Build graph according to slide
    adj[1] = {5, 0};         // s -> w, r
    adj[5] = {1, 2, 6};      // w -> s, t, x
    adj[0] = {1, 4};         // r -> s, v
    adj[2] = {5, 3};         // t -> w, u
    adj[6] = {5, 7};         // x -> w, y
    adj[4] = {0};            // v -> r
    adj[3] = {2};            // u -> t
    adj[7] = {6};            // y -> x
    vector<int> color(vertex, 0); // 0=WHITE, 1=GRAY, 2=BLACK
    vector<int> d(vertex, INF);
    vector<int> pi(vertex, -1);

    int s = 1; // source = s

    color[s] = 1; // GRAY
    d[s] = 0;
    pi[s] = -1;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : adj[u])
        {
            if (color[v] == 0)
            {                 // WHITE
                color[v] = 1; // GRAY
                d[v] = d[u] + 1;
                pi[v] = u;
                Q.push(v);
            }
        }

        color[u] = 2; // BLACK
    }
    return 0;
}