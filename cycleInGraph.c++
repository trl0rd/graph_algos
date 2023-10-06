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

    bool cycleFound(int &i,vector<int> &visited,vector<int> &dfsVisited){
        visited[i] = true;
        dfsVisited[i] = true;
        for(auto neighbour:adj[i]){
            if(!visited[neighbour]){
                bool cycle = cycleFound(neighbour,visited,dfsVisited);
                if(cycle)
                    return true;
            }
            else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[i]=false;
        return false;
    }

    void DFS(){
        vector<int> visited(v,false);
        vector<int> dfsVisited(v,false);
        for(int i=0 ; i<v ; i++){
            if(!visited[i]){
                bool cycle = cycleFound(i,visited,dfsVisited);
                if(cycle){
                    cout<<"Cycle is present";
                    return ;
                }
            }
        }
        cout<<"No cycle found";
    };

};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    // g.addEdge(2,0);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.DFS();
    return 0;
}
