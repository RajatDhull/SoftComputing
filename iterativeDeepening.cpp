#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<int> adj[],int depth,int num,int curr){
    if(depth<=-1) return false;

    if(curr==num){
        return true;
    }

    for(auto i:adj[curr]){
        if(dfs(adj,depth-1,num,i)){
            return true;
        }
    }
    return false;
}

void printGraph(int v,vector<int> v1[]){
    cout<<"The adjacency list is :\n";
    for(int i=0;i<v;i++){
        cout<<i<<" => ";
        for(int j=0;j<v1[i].size();j++){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    cout<<"Enter the number of nodes and edges:\t";
    int v,e;cin>>v>>e;

    cout<<"Is it undirected/directed(press 0/1): ";
    bool x=0;
    cin>>x;

    vector<int> adj[v];
    cout<<"Enter the edge values:\t";
    for(int i=0;i<e;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        if(x!=1) adj[b].push_back(a);
    }

    cout<<"The graph is:\n";
    printGraph(v,adj);
    cout<<endl;

    cout<<"Enter the max depth:\t";
    int d;cin>>d;
    cout<<"Enter the number to search:\t";
    int num;cin>>num;
    bool flag=0;
    for(int i=1;i<=d;i++){
        if(dfs(adj,i,num,0)){
            flag=1;
            cout<<"Found at depth "<<i<<endl;break;
        }
    }
    if(!flag) cout<<"Not found till depth"<<d<<"\n";
}
