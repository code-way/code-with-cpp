// Bellman-Ford Algorithm
// It is also an algorithm to find single source shortest path but dijkstra do the same.
// what makes it different actually dijkstra will not work for negative edge as 
// Dijkstra is a greedy approach (pick minimum) but Bellman-Ford is a Dynamic programming approach

// Here it can also find if the graph contains a cycle or not.

// How it works : As it is dynamic programming approach so it will see all the possibility
// If a graph has n vertex then for that vertex there is atmost n-1 edge
// so we have to do the traversal for n-1 times and do relaxation(relaxation?)

// Relaxation means i have to check this condition (dis[u] + w(u,v) < dis[v])
// after n-1 times if this condition is true for any vertex i.e. there is a negative cycle in that graph
// because if a graph has cycle then everytime it will reduce the value.

#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
	int ver,edge;
	// To store the node with distance
	unordered_map<T,list<pair<T,int>>> adjList;
public:
	Graph(int v,int e){
		this->ver = v;
		this->edge = e;
	}
	void addEdge(T u,T v,int dist,bool bid=true){
		adjList[u].push_back({v,dist});
		if(bid){
			adjList[v].push_back({u,dist});
		}
	}
	void bellmanFord(T src){
		// set all the distance to infinity
		unordered_map<T,int> dis;
		for(auto i:adjList){
			dis[i.first] = INT_MAX;
		}
		dis[src] = 0;
		// Traverse the graph for n-1 times 
		for(int i=0;i<ver-1;i++){
	        for(auto i:adjList){
    	        for(auto j:i.second){
    	        	T u = i.first;
    	        	T v = j.first;
    	        	int weight = j.second;
    	        	// Relaxation for every vertex
    	            if(dis[u] + weight <dis[v]){
    	                dis[v] = dis[u] + weight;
    	            }
    	        }
	        }
	    }
	    // After n-1 times if the condition of relaxation is true i.e. cycle is present
	    for(auto i:adjList){
	        for(auto j:i.second){
	        	T u = i.first;
	        	T v = j.first;
	        	int weight = j.second;
	            if(dis[u] + weight <dis[v]){
					cout<<"Negative Cycle is present";
                	return;    	            
	        	}
	        }
	    }
	   cout<<"there is no negative cycle in this graph";
	}
};
int main(){
	// Negative cycle is not present
	// Graph<int> g(5,8);
	// g.addEdge(0,1,-1);
	// g.addEdge(0,2,4);
	// g.addEdge(1,2,3);
	// g.addEdge(1,3,2);
	// g.addEdge(1,4,2);
	// g.addEdge(3,2,5);
	// g.addEdge(3,1,1);
	// g.addEdge(4,3,-3);

	// Negative cycle is there
	Graph<int> g(3,3);
	g.addEdge(0,1,-5);
	g.addEdge(1,2,-6);
	g.addEdge(2,0,-9);
	g.bellmanFord(0);
}
