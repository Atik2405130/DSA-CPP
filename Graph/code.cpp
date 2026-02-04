#include<iostream>
using namespace std;
#include<vector>
#include<list>

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
    void print(){
        for(int i=0;i<vertices;i++){
            cout<<i<<": ";
            for(int val:l[i]){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5);
    g.add(0,1);
    g.add(1,3);
    g.add(1,4);
    g.add(2,4);
    g.add(2,3);
    g.print();
}