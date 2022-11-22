#include<bits/stdc++.h>
using namespace std;

int h_function(int node, int goal_node){
    return abs(goal_node - node);
}

int A_star(vector<vector<pair<int, int>>> &adj, int src, int dest, int n){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > open;
    set<int> closed;
    int c = h_function(src, dest);
    open.push({c, {src, 0}});
    int count = 0;
    int upper_limit = 100;

    while(!open.empty() && count++<upper_limit){
        auto it = open.top();
        open.pop();
        int node = it.second.first;
        int prev_g = it.second.second;

        if(node == dest) return prev_g;
        if(closed.find(node) == closed.end()){
            continue;
        }

        for(auto neighbour : adj[node]){
            int h = h_function(neighbour.first, dest);
            int g = prev_g + neighbour.second;
            open.push({h+g, {neighbour.first, g}});
        }
    }
    return INT_MAX;

}

int main(){
    
    int n;
    cout<<"Enter total number of nodes : ";
    cin>>n;
    
    vector<vector<pair<int, int>> > adj(n);
 
    int m;
    cout<<"Enter total number of edeges : ";
    cin>>m;
    for(int i =0; i<m; i++){
        cout<<"Enter u, v, w : ";
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src, destination;
    cout<<"Enter source node : ";
    cin>>src;
    cout<<"Enter destination node : ";
    cin>>destination;

    cout<<A_star(adj, src, destination, n);

    return 0;
}