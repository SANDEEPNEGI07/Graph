#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    
    bool dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &color, int currColor){
        color[node] = currColor;
        
        for(auto &it : adj[node]){
            if(color[it] == color[node]) 
                return false;
            
            if(color[it] == -1){
                int newColor = 1 - color[node]; // Way to get different color
                
                if(dfs(it, adj, color, newColor) == false){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &e : edges){
            int u = e[0], v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(dfs(i, adj, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};