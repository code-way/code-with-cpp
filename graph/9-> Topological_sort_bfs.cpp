// Topological Sort Using BFS - KAHN'S ALGORITHM
// Uses a modified BFS
// A queue and array/map for storing indegree of each vertex is used
// Algorithm Starts from finding vertices with 0 indegree.

// Approach :
// Assign every node as indegree value(indegree :- Number of nodes directed to it) and there must be some node which has zero indegree 
// so,To start the ordering we find the zero indegree and push it into the queue.
// now same logic of bfs, take the front element (i.e zero indegree) popped it and print it 
// and for every neighbour of that node decrease one indegree as we removed that node and check if indegree of neighbour is zero then pushed into the queue


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
	void bfsTopological(){
		queue<T> q;
	    map<T,int> indegree;
	    // For every node initialise indegree as zero.
	    for(auto i:adjList){
	    	T node = i.first;
	    	indegree[node] = 0;
	    }
	    // assign the indegree's to every node
	    for(auto element:adjList){
	    	for(auto v:element.second){
	    		indegree[v]++;
	    	}
	    }
	    // find the 0 indegree and pushed it into the queue
	    for(auto i:adjList){
	    	T node = i.first;
	    	if(indegree[node]==0){
	    		q.push(node);
	    	}
	    } 
	    while(!q.empty()){
	    	T node = q.front();
	    	q.pop();
	    	cout<<node<<"-> ";
	    	for(auto neighbour:adjList[node]){
	    		indegree[neighbour]--;
	    		if(indegree[neighbour]==0){
	    			q.push(neighbour);
	    		}
	    	}
	    }

	}
};
int main(){
	Graph<string> g;
	g.addEdge("English","Programming Logic",false);
	g.addEdge("Maths","Programming Logic",false);
	g.addEdge("Programming Logic","HTML",false);
	g.addEdge("Programming Logic","Python",false);
	g.addEdge("Programming Logic","Java",false);
	g.addEdge("Programming Logic","JS",false);
	g.addEdge("HTML","CSS",false);
	g.addEdge("CSS","JS",false);
	g.addEdge("JS","Web Development",false);
	g.addEdge("Python","Web Development",false);
	g.addEdge("Java","Web Development",false);
	g.bfsTopological();
	return 0;
} 