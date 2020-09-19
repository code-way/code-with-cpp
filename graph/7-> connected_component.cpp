// Number of connected component 

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    int V;
	map<T,list<T> > adjList;
public:
	void addEdge(T u,T v,bool bid=true){
		 adjList[u].push_back(v);
		 if(bid){
		 	adjList[v].push_back(u);
		 }
	}
	void dfsHelper(T src, map<T,bool>& vis){
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
	    map<T,bool> vis;
	    for(auto i:adjList){
	        T city = i.first;
	        vis[city] = false;
	    }
	    // For the first component we can use dfsHelper() function using source node, so component=1
	    int component = 1;
	    dfsHelper(src,vis);
	    cout<<endl;
	    // For other component we have to use again dfsHelper() function so that if any node is not visited then it will visit and print
	    for(auto i: adjList){
	    	T city = i.first;
	    	if(!vis[city]){
	    		dfsHelper(city,vis);
	    		component++;
	    		cout<<endl;
	    	}
	    }
	    
	   cout<<"The current graph had "<<component<<" component";
	}
};
int main(){
	Graph<string> g;
	g.addEdge("Amritsar","Jaipur");
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Delhi","Jaipur");
	g.addEdge("Mumbai","Jaipur");
	g.addEdge("Mumbai","Bhopal");
	g.addEdge("Delhi","Bhopal");
	g.addEdge("Mumbai","Banglore");
	g.addEdge("Agra","Delhi");
	g.addEdge("Andaman","Nicobar");
	g.dfs("Amritsar");
	return 0;
}