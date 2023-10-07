#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> iPair;

class Graph{
    int v;
    list<pair<int,int>> *adj;
    public:
    Graph(int v){
        this->v=v;
        adj = new list<pair<int,int>>[v];
    }

    void addEdge(int v,int w,int weight){
        adj[v].push_back({w,weight});
        adj[w].push_back({v,weight});
    }

    void print(){
        for(int i=0;i<v;i++){
            cout<<i<<" : ";
            for(auto j:adj[i]){
                cout<<"("<<j.first<<","<<j.second<<")"<<"\t";
            }
            cout<<endl;
        }
    }

    void shortestPath(int target){
        priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
        vector<int> dist(v,INT_MAX);
        pq.push({0,target});
        dist[target]=0;
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            list<iPair>::iterator i;
            for(i=adj[u].begin();i!=adj[u].end();i++){
                int v=(*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                }
            }
        }
         printf("Vertex Distance from Source\n");
        for (int i = 0; i < v; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,2,2);
    g.addEdge(0,1,4);
    g.addEdge(1,2,3);
    g.addEdge(1,4,2);
    g.addEdge(2,3,1);
    g.addEdge(3,4,7);

    g.shortestPath(0);

    g.print();
    return 0;
}