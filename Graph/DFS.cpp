#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<queue>

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
    void DFS_helper(int u,vector<bool>&vis){
        cout<<u<<" ";
        vis[u]=true;
        for(int val:l[u]){
            if(!vis[val]){
                DFS_helper(val,vis);
            }
        }
    }
    void dfs(){
        vector<bool>vis(vertices,false);
        int src=0;
        DFS_helper(src,vis);
        cout<<endl;
    }
};


int main(){
    Graph g(5);
    g.add(0,1);
    g.add(1,2);
    g.add(1,3);
    //g.add(2,3);
    g.add(2,4);
    g.dfs();

}