#include <bits/stdc++.h>
using namespace std;

// if parent is same then there is a cycle
// if not parent then union both set


class Solution {
  public:
  
    vector<int> parent;
    vector<int> rank;
    
    int find(int i){
        if(i == parent[i]){
            return i;
        }

        return parent[i] = find(parent[i]); // Storing the leader of the same set to all the element of that set.
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        // parent are same both x and y belongs to the same set
        if(x_parent == y_parent) return ;

        // rank of x set is greater
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }

        if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }

        // both rank of x set and y set is equal.
        else{
            parent[y_parent] = x_parent;
            rank[x_parent]++; //increase the rank of the x set leader.
        }
    }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        
        parent.resize(V);
        rank.resize(V);
        
        for(int i = 0; i < V; i++){
            parent[i] = i; // all element have there own parent initially.
            rank[i] = 1; // all element has rank 1 initially.
        }
        
        for(int u = 0; u < V; u++){
            for(int &v : adj[u]){
                
                if(u < v){
                    int u_parent = find(u);
                    int v_parent = find(v);
                    
                    if(u_parent == v_parent) return true;
                    
                    Union(u, v);
                }
            }
        }
        return false;
    }
};