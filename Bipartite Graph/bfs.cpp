#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool bfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &color, int currColor){
        color[node] = currColor;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto &v : adj[u]){
                if(color[v] == color[u]) 
                    return false;
            
                else if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
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
                if(bfs(i, adj, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};