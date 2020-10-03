// Dijkstra Algorithm : It is use to find the single source shortest path in a weighted Graph
// It works only for positive edge weights
// Edge can be either bidirectional or single direction
// here we can't use BFS as the edge have some weight
		
// Let's take one example : From a city find the min distances to all other cities which has some path to reach 		
// Algorithm : 
// first mark the source node distance as zero and all others node distances as infinity
// check if(dis[u]+edgeDistance < dis[v]) then dis[v] = dis[u] + edgeDistance

#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
	// To store the node with distance
	unordered_map<T,list<pair<T,int>>> adjList;
public:
	void addEdge(T u,T v,int dist,bool bid=true){
		adjList[u].push_back({v,dist});
		if(bid){
			adjList[v].push_back({u,dist});
		}
	}
	void print(){
		for(auto i: adjList){
			cout<<i.first<<"->";
			for(auto j : i.second){
				cout<<"("<<j.first<<","<<j.second<<")";
			}
			cout<<endl;
		}
	}
	void dijkstraSSSP(T src){
		// set all the distance to infinity
		unordered_map<T,int> dis;
		for(auto i:adjList){
			dis[i.first] = INT_MAX;
		}
		// Make a set to find out a node with the minimum distance
		set<pair<int,T>> s; // because we want to sort using distance so pair<int,T> (as set sorting according to 1st parameter)
		s.insert({0,src}); //(Amritsar,0)
		dis[src] = 0;
		while(!s.empty()){
			// Find the pair at the front
			auto p = *(s.begin());
			T node = p.second; //Amritsar
			int nodeDist = p.first; // 0
			s.erase(s.begin());
			for(auto childPair : adjList[node]){
				// Amritsar -> (Delhi,1) (Jaipur,4) 
				// dis["Delhi"] = INT_MAX
				if( nodeDist + childPair.second < dis[childPair.first]){
					// In the set updation of a particular is not possible
					// we have to remove the old pair, and insert the new pair to simulation updation
					auto f = s.find({dis[childPair.first],childPair.first});
					if(f!=s.end()){
						s.erase(f); // (INT_MAX,Delhi)
					}
					// update the distance for current node
					dis[childPair.first] = nodeDist + childPair.second; // dis["Delhi"] = 1
					// after updation the node distance insert into the set
					s.insert({dis[childPair.first],childPair.first}); //(Delhi,1)

				}
			}
		}

		// print the distance 
		cout<<src<<"->";
		for(auto i:dis){
			cout<<"("<<i.first<<","<<i.second<<")";
		}

	}
};
int main(){
	Graph<string> india;
	india.addEdge("Amritsar","Delhi",1);
	india.addEdge("Amritsar","Jaipur",4);
	india.addEdge("Jaipur","Delhi",2);
	india.addEdge("Jaipur","Mumbai",8);
	india.addEdge("Bhopal","Agra",2);
	india.addEdge("Mumbai","Bhopal",3);
	india.addEdge("Agra","Delhi",1);
	// india.print();
	india.dijkstraSSSP("Amritsar");
}