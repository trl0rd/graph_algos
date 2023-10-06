#include<bits/stdc++.h>

using namespace std;

class Graph{
    int v;
    vector<list<int>> adj;

    public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int v){
    this->v=v;
    adj.resize(v);
}

void Graph :: addEdge(int v, int w){
    adj[v].push_back(w);
} 

void Graph :: BFS(int s){
    vector<bool> visited(v,false);
    list<int> queue;
    visited[s]=true;
    queue.push_back(s);

    while(!queue.empty()){
        s=queue.front();
        queue.pop_front();
        cout<<s<<" ";
        for(auto adjacent:adj[s]){
            if(!visited[adjacent]){
                visited[adjacent]=true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main(){
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(2,0);
    G.addEdge(2,3);
    G.addEdge(3,3);
    G.BFS(2);
    return 0;
}

