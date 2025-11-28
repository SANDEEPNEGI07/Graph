// DFS is used

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion){
        visited[node] = true;
        inRecursion[node] = true;
        
        for(auto &it : adj[node]){
            if(!visited[it] && dfs(it, adj, visited, inRecursion)){
                return true;
            }
            else if(inRecursion[it]){
                return true;
            }
        }
        inRecursion[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && dfs(i, adj, visited, inRecursion)){
                return true;
            }
        }
        return false;
    }
};