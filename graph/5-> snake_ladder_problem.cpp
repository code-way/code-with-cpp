// LINK:- https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0
// You can first go with SSSP then try this question
// this problem is basically extension of single source shotest path(SSSP). We have to reach from initial to final point in shortest path

#include<bits/stdc++.h>
using namespace std;
class Graph{
        unordered_map<int,list<int>> adjList;
    public:
        void addEdge(int u,int v){
            adjList[u].push_back(v);
        }
        // Same as SSSP 
        int dfs(int src,int des){
            queue<int> q;
            q.push(src);
            unordered_map<int,int> dis;
            for(auto i: adjList){
                dis[i.first]=INT_MAX;
            }
            dis[src]=0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto i: adjList[node]){
                    if(dis[i]==INT_MAX){
                        q.push(i);
                        dis[i] = dis[node] + 1;
                    }
                }
            }
            return dis[des];
        }
    
};
int main()
 {
     int t;
     cin>>t;
     while(t--){
         Graph g;
         // Here we are create a board array as we have to assign some weight for ladder and snake point so, In the que it is given 5*6 matrix so i created with some buffer and initialise with zero
        int n,board[50]={0};
        cin>>n;
        for(int i=0;i<n;i++){
            // Here u and v is basically a stair to climb up and snake to go down (u->source to v->destination)
            int u,v;
            cin>>u>>v;
            // Let's Say if a dice is thrown and get 2, it is currently at position 4 so by increment 2, it goes to 6 but 6 is transient point (i.e A stair or a snake is present at that position) so it directly goes to snake or stair position by climb up or go down.
            // so, I stored in a array with position is u and value is (destination - source) v.
            board[u]=v-u;
        }
        // For every position with every outcome create an edge of graph As it is directed graph with same weight so, we can use SSSP to find the shortest distance from source to destination
        for(int u=1;u<=30;u++){
            for(int dice=1;dice<=6;dice++){
                int v = u + dice + board[u+dice];
                g.addEdge(u,v);
            }
        }
        cout<<g.dfs(1,30)<<endl;
     }
	return 0;
}