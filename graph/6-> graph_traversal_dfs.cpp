// Depth First Search :
// It is also a graph traversal like "BFS" but with recursive approach.
// It traverses graph 'Depth First',Starting from source,then picks one of the unvisited neighbours and visit it.
// This process is repeated and traversal goes deeper into a branch until it reaches a vertex where it can't go further.
// After this happens, DFS will explore other unvisited neighbours.


// Complexity
// Time  Complexity : O(V+E) (using adjacency list.. Because in the worst case every vertex and every edge will be traversed) 
//					  O(V^2) (using adjacency matrix.. Because in the worst case entire adjacency matrix will be cover)
// Space Complexity : O(V)

// Applications
// Traversing the graph recursively.
// Finding the connected components.(useful in Image Segmentation and Clusturing Algorithm)
// Easy to implement but can't find shortest path
// Flood-Fill Algorithm used in Flood Bucket tool in paint, photoshop etc.
// Also used in Cycle Detection and Topological Sorting.


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
	void dfsHelper(T src, bool vis[]){
		// whenever come to a node, mark it visited
		vis[src] = true;
		cout<<src<<" ";
		// Try to find out a node which is neighbour of current node and not yet visited 
		for(auto neighbours: adjList[src]){
			if(!vis[neighbours]){
				dfsHelper(neighbours,vis);
			}
		}
	}
	void dfs(T src){
	    // First mark all nodes as unvisited
	    bool vis[V]={false};
	    dfsHelper(src,vis);
	}
};
int main(){
	Graph<int> g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.dfs(0);
	return 0;
}