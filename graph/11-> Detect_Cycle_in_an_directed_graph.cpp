// Back-Edge : It is an edge such that from a vertex with state "currently in stack" to a vertex with
// state "current in stack" (ancenstor) in DFS traversal is called the back-edge. 

// If u->v is a back-edge then u comes in the path of v or u is an ancestor of v.
// "current in stack" means the current node has been visited but not completed,
// hence present in the DFS call stack.

// So,for cycle graph we check for back-edge!
// This can be achieved by adding one more array "in stack" apart from "visited" array.
// The "visited" state means the current node has been explored and DFS has been completed.

#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
	map<T,list<T>> adjList;
public:
	void addEdge(T u,T v,bool bid=true){
		adjList[u].push_back(v);
		if(bid){
			adjList[v].push_back(u);
		}
	}
	bool isCyclicHelpher(T node, map<T,bool>& vis,map<T,bool>& inStack){
		// Processing the current node - visited,inStack
		vis[node] = true;
		inStack[node] = true;

		// Explore the neighbour of the node
		for(auto neighbour : adjList[node]){
			// if the current node is not visited but it's further branch is leading to a cycle
			// or current node is visited as well as present in current call stack
			if(!vis[neighbour] && isCyclicHelpher(neighbour,vis,inStack) || inStack[neighbour]){
				return true;
			}
		}
		inStack[node] = false;
		return false;
	}
	bool isCyclic(){
		map<T,bool> vis;
		map<T,bool> inStack; // default set as false
	
		// To check for cycle in each dfs tree
		for(auto i: adjList){
			T node = i.first;
			if(!vis[node]){
				bool cyclePresent = isCyclicHelpher(node,vis,inStack);
				if(cyclePresent){
					return true;
				}else{
					return false;
				}
			}
		}
	}
};
int main(){
	Graph<int> g;
	g.addEdge(0,2);
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(3,0);
	g.addEdge(4,5);
	g.addEdge(1,5);
	if(g.isCyclic()){
		cout<<"Cycle is present";
	}else{
		cout<<"Cycle not found!";
	}
}