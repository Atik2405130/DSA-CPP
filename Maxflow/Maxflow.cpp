#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;

int bfs(int source,int sink,vector<vector<int>>&adj,vector<vector<int>>&capacity,vector<int>&parent){
    fill(parent.begin(),parent.end(),-1);
    queue<pair<int,int>>q;
    parent[source]=-2;
    q.push({source,INT_MAX});
    while(q.size()>0){
        int u=q.front().first;
        int assumed_flow=q.front().second;
        q.pop();
        for(int v:adj[u]){
            if(parent[v]==-1 && capacity[u][v]>0){
                parent[v]=u;
                int actual_flow=min(assumed_flow,capacity[u][v]);
                if(v==sink)return actual_flow;
                q.push({v,actual_flow});
            }
        }
    }
    return 0;
}
int maxflow(int N,int source,int sink,vector<vector<int>>&adj,vector<vector<int>>&capacity){
    int total_flow=0;
    vector<int>parent(N);
    while(true){
        int path_flow=bfs(source,sink,adj,capacity,parent);
        if(path_flow==0){
            break;
        }
        total_flow+=path_flow;
        int current=sink;
        while(current!=source){
            int previous=parent[current];
            capacity[previous][current]-=path_flow;
            capacity[current][previous]+=path_flow;
            current=previous;
        }
    }
    return total_flow;
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>>adj(N+1);
    vector<vector<int>>capacity(N+1,vector<int>(N+1));
    for(int i=0;i<M;i++){
        int u,v,cap;
        cin>>u>>v>>cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v]+=cap;
    }
    int source=0;
    int sink=N-1;
    cout<<maxflow(N,source,sink,adj,capacity)<<endl;
}