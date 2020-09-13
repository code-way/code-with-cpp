//What is Graphs?
//Graph is a data structure which is represented as a finite set of nodes and edges. These nodes are called vertices and edges are used to    
//connect two vertices

//there is basically three ways to traverse a graph :-
// 1) Edge list (using list of pair)
// 2) Adjacency matrix (using 2d array)
// 3) Adjacency List (using list of array) -- Efficient one

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l; 
public:
	Graph(int v){
		V=v;
		l= new list<int>[V];
	}
	void addEdge(int u,int v,bool bid=true){
		 l[u].push_back(v);
		 if(bid==true){
		 	l[v].push_back(u);
		 }
	}
	void print(){
		for(int i=0;i<V;i++){
			cout<<i<<"-> ";
			for(auto neighbour:l[i]){
				cout<<neighbour<<", ";
			}
			cout<<endl;
		}
	}
};
int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.print();
	return 0;
}