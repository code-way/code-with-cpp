
//Generic Graph Traversal
//using example of process management

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T> > adjList;
public:
	void addEdge(T u,T v,bool bid=true){
		 adjList[u].push_back(v);
		 if(bid){
		 	adjList[v].push_back(u);
		 }
	}
	void print(){
	    //Iterate over the map
		for(auto i:adjList){
			cout<<i.first<<"-> ";
			//i.second is a linkedlist
			for(auto entry:i.second){
				cout<<entry<<", ";
			}
			cout<<endl;
		}
	}
};
int main(){
	Graph<string> g;
	g.addEdge("New","Ready",false);
	g.addEdge("Ready","Run",true);
	g.addEdge("Run","Termination",false);
	g.addEdge("Run","Wait/Block",false);
	g.addEdge("Wait/Block","Suspend wait",true);
	g.addEdge("Suspend wait","Suspend/Ready",false);
	g.addEdge("Suspend/Ready","Ready",true);
	g.addEdge("Wait/Block","Ready",false);
	g.print();
	return 0;
}