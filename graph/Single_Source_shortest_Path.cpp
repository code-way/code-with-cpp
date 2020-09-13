// Single Source Sortest Path (SSSP) : calculate the shortest path from a single source node to all the other nodes.
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    int V;
	map<T,list<T> > adjList;
public:
    Graph(int v){
        V=v;
    }
	void addEdge(T u,T v,bool bid=true){
		 adjList[u].push_back(v);
		 if(bid){
		 	adjList[v].push_back(u);
		 }
	}
	void SSSP(T src){
        // No need to use visited array, we can mantain the distances using map and mark all the node distances as Infinity
        map<T,int> dis;
        for(auto i:adjList){
            dis[i.first] = INT_MAX;
        }
	    queue<T> q;
	    q.push(src);
	    // distance of source to source node is zero
	    dis[src]=0; 
	    while(!q.empty()){
	        T node = q.front();
	        q.pop();
	        // For every neighbour of that node check if the distance is being calculated or not, if not then push it to queue and calculate the distances..
            // when a node is traverse for the first time then already the distance is minimum as un-weighted graph(it has no edge weight assigned explicitly i.e every edge has same weight)
            for(auto neighbour: adjList[node]){
                if(dis[neighbour]==INT_MAX){
	                q.push(neighbour);
                    dis[neighbour] = dis[node] + 1;
                }
            }
        }
        // print the distance to all the nodes
        for(auto i: adjList){
            T node = i.first;
            cout<<"Dist of "<<node<<" from "<<src<<" is "<<dis[node]<<endl;
        }
	}
};
int main(){
	Graph<int> g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.SSSP(0);
	return 0;
}