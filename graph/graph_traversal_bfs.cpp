// A graph traversal is a method to traverse all nodes in a Graph.
// It is also use to search a particular node in a dense Graph.
// There are two types of traversals:
// BFS (Bredth First Search)
// DFS (Depth First Search)

// Bredth First Search :-
// -> It traverses graph 'Bredth-first', Starting from source, then direct neighbours of source vertex, and then next layer and so on.
// -> Iterative approach, like level order traversal in tree.
// -> uses a Queue Data Structure to maintain FIFO ordering, another Data Structure (array/map) is used to maintain the list of vertices visited so far.


// Complexity
// Time  Complexity : O(V+E) (using adjacency list) 
// explanation : because every node is pushed once into the queue and it's popped out once from the queue and In the worst case we have to also traverse the edge.
// Space Complexity : O(V)

// Applications
// Finding the single source shotest path in un-weighted graph.
// Finding the connected components.
// can be used in Flood Fill algorithm in 'Bucket' Tool in Photoshop, Paints etc for the colouring regions with same colours.

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
	void bfs(T src){
	    // First mark all nodes as unvisited
	    bool vis[V]={false};
	    queue<T> q;
	    // push the first element to queue and mark as visited
	    q.push(src);
	    vis[src]=true;
	    while(!q.empty()){
	        // popped the front element from queue and print 
	        T node = q.front();
	        q.pop();
	        cout<<node<<" ";
	        // For the neighbours of the current node, find out the nodes which are not visited
            for(auto neighbour: adjList[node]){
                if(!vis[neighbour]){
	                q.push(neighbour);
	                vis[neighbour]=true;
                }
            }
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
	g.bfs(0);
	return 0;
}