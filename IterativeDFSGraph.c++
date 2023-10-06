#include<bits/stdc++.h>

using namespace std;

class Graph{
    int v;
    list<int> *adj;
    public:
    Graph(int v){
        this->v=v;
        adj = new list<int>[v];
    }
    void addEdge(int v,int w){
        adj[v].push_back(w);
    }
    void DFS(int s){
        vector<bool> visited(v,false);
        stack<int> track;
        track.push(s);
        while(!track.empty()){
            s=track.top();
            track.pop();
            if(!visited[s]){
                cout<<s<<" ";
                visited[s]=true;
            }
            for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
                if (!visited[*i])
                    track.push(*i);
        }
    }
};


int main(){
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS(0);
    return 0;
}