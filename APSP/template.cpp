#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const long long INF = (1LL << 60);

class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    vector<vector<long long>> dist;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
    }

    void floydWarshall() {
        dist.assign(V, vector<long long>(V, INF));

        for(int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }

        for(int u = 0; u < V; u++) {
            for(auto e : adj[u]) {
                int v = e.first;
                int w = e.second;

                // In case multiple edges exist
                dist[u][v] = min(dist[u][v], (long long)w);
            }
        }

        for(int k = 0; k < V; k++) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {

                    if(dist[i][k] == INF || dist[k][j] == INF)
                        continue;

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }
    }

    void answerQuery(int source, int destination, int A, int B) {
        long long throughA = INF;
        long long throughB = INF;

        // source -> A -> destination
        if(dist[source][A] != INF &&
           dist[A][destination] != INF) {

            throughA = dist[source][A]
                     + dist[A][destination];
        }

        // source -> B -> destination
        if(dist[source][B] != INF &&
           dist[B][destination] != INF) {

            throughB = dist[source][B]
                     + dist[B][destination];
        }

        if(throughA == INF && throughB == INF) {
            cout << -1 << endl;
        }
        else if(throughA < throughB) {
            cout << throughA << " " << A << endl;
        }
        else if(throughB < throughA) {
            cout << throughB << " " << B << endl;
        }
        else {
            // Equal distance: print smaller hub
            cout << throughA << " " << min(A, B) << endl;
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    // N+1 works for both 0-based and 1-based station numbering
    Graph g(N + 1);

    for(int i = 0; i < M; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        // Directed edge
        g.addEdge(u, v, wt);
    }

    int A, B;
    cin >> A >> B;

    g.floydWarshall();

    int Q;
    cin >> Q;

    while(Q--) {
        int source, destination;
        cin >> source >> destination;

        g.answerQuery(source, destination, A, B);
    }

    return 0;
}