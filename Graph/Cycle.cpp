#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph
{
    list<int>*l;
    int vertices;
    public:
    Graph(int v){
        vertices=v;
        l=new list<int>[vertices];
    }
    void add(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u); // Undirected Graph;
    }
    bool isCycleDFS(int src,int par,vector<bool>&vis){
        vis[src]=true;
        list<int>neigh=l[src];
        for(int v:neigh){
            if(!vis[v]){
                if(isCycleDFS(v,src,vis))return true;
            }
            else if(v!=par){
                return true;
            }
        }
        return false;
    }
    bool ifCycle(){
        vector<bool>vis(vertices,false);
        for(int i=0;i<vertices;i++){
            if(isCycleDFS(i,-1,vis)){
                return true;
            }
        }
        return false;
    }
};
int main(){
    Graph g(5);
    g.add(0,1);
    g.add(1,2);
    g.add(1,3);
    g.add(2,3);
    g.add(2,4);
}