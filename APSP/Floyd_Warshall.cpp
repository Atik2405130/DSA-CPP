#include<iostream>
#include<vector>
using namespace std;

class Graph{
    public:
        vector<vector<pair<int,int>>>adj;
        int V;
        Graph(int V){
            this->V=V;
            adj.resize(V);
        }
        void addEdge(int u,int v,int wt){
            adj[u].push_back({v,wt});
        }
        void floydWarshall(){
            const int INF=1e9;
            vector<vector<int>>dist(V,(vector<int>(V,INF)));
            for(int i=0;i<V;i++){
                dist[i][i]=0;
            }
            for(int u=0;u<V;u++){
                for(auto e:adj[u]){
                    int v=e.first;
                    int w=e.second;
                    dist[u][v]=w;
                }
            }
            for(int k=0;k<V;k++){
                for(int i=0;i<V;i++){
                    for(int j=0;j<V;j++){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(dist[i][j]==INF){
                        cout<<"INF ";
                    }
                    else{
                        cout<<dist[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
        }
};
int main(){
    Graph g(4);
    g.addEdge(0,1,4);
    g.addEdge(0,2,11);
    g.addEdge(1,2,2);
    g.addEdge(1,3,8);
    g.addEdge(2,3,3);
    g.floydWarshall();
}
