#include<iostream>
#include<vector>
#include<queue>
#include<list>
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
    bool isCycleBFS(int src,vector<bool>&vis){
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src]=true;
        while(q.size()>0){
            int u=q.front().first; // first is current node
            int parU=q.front().second; //second is parent
            q.pop();
            list<int>neigh=l[u];
            for(int v:neigh){
                if(!vis[v]){
                    q.push({v,u});
                    vis[v]=true;
                }
                else if(v!=parU){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(){
        vector<bool>vis(vertices,false);
        for(int i=0;i<vertices;i++){
            if(!vis[i]){
                if(isCycleBFS(i,vis)){
                    return true;
                }
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