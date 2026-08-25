#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
using namespace std;

struct Flight
{
    string id;
    string departure_city;
    string arrival_city;
    int departure_time;
    int arrival_time;
};

int extract_minute(string &t){
    int hr=stoi(t.substr(0,2));
    int min=stoi(t.substr(3,2));
    return hr*60+min;
}

void addEdge(int u,int v,int cap,vector<vector<int>>&adj,vector<vector<int>>&capacity){
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v]+=cap;
}

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
    int F;
    cin>>F;
    vector<Flight>f(F);
    for(int i=0;i<F;i++){
        string arrival_time;
        string departure_time;
        cin>>f[i].id>>f[i].departure_city>>f[i].arrival_city>>departure_time>>arrival_time;
        f[i].departure_time=extract_minute(departure_time);
        f[i].arrival_time=extract_minute(arrival_time);
    }
    int source=0;
    int sink=2*F+1;
    int nodes_count=2*F+2;

    vector<vector<int>>adj(nodes_count);
    vector<vector<int>>capacity(nodes_count,vector<int>(nodes_count,0));
    vector<vector<bool>>possible(F,vector<bool>(F,false));

    for (int i = 0; i < F; i++)
    {
        int leftNode = 1 + i;
        addEdge(source,leftNode,1,adj,capacity);
    }

    const int time_needed=180; // 3 hr

    for(int i=0;i<F;i++){
        for(int j=0;j<F;j++){
            if(i==j){
                continue;
            } //change needed
            if(f[i].arrival_city==f[j].departure_city && f[i].arrival_time+time_needed<=f[j].departure_time){
                possible[i][j]=true;

                int left_node=1+i;
                int right_node=1+F+j;
                addEdge(left_node,right_node,1,adj,capacity);
            }
        }
    }
    for(int j=0;j<F;j++){
        int right_node=1+F+j;
        addEdge(right_node,sink,1,adj,capacity);
    }
    int max_match=maxflow(nodes_count,source,sink,adj,capacity);

    int minimum_aircraft=F-max_match;
    vector<int>next_flight(F,-1);
    vector<int>prev_flight(F,-1);

    for(int i=0;i<F;i++){
        for(int j=0;j<F;j++){
            if(!possible[i][j]){
                continue;
            }
            int left_node=1+i;
            int right_node=1+F+j;
            if (capacity[left_node][right_node] == 0)
            {
                next_flight[i] = j;
                prev_flight[j] = i;
            }
        }
    }
    cout << "Number of Aircraft: "<< minimum_aircraft << '\n';
    int aircraft_no=1;

    for(int i=0;i<F;i++){

        if(prev_flight[i]!=-1){
            continue;
        }
        cout<<"Aircraft "<<aircraft_no<<": ";
        int current=i;
        while(current!=-1){
            cout<<f[current].id;
            current=next_flight[current];
            if(current!=-1){
                cout<<" -> ";
            }
        }
        cout<<'\n';
        aircraft_no++;
    }
}