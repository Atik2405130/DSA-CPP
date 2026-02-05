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
    void BFS(){
        vector<bool>status(vertices,false);
        queue<int>q;
        q.push(0);
        status[0]=true;
        while(q.size()>0){
            int src=q.front();
            q.pop();
            cout<<src<<": ";
            for(int neighbour:l[src]){
                if(!status[neighbour]){
                    cout<<neighbour<<" ";
                    status[neighbour]=true;
                    q.push(neighbour);
                }
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);
    g.add(0,1);
    g.add(1,2);
    g.add(1,3);
    g.add(2,3);
    g.add(2,4);
    g.BFS();
}