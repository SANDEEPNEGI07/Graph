// DFS is used

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    
    bool dfs(int node, vector<vector<int>> &edges, vector<bool> &visited, int parent){
        visited[node] = true;
        
        for(auto &it : edges[node]){
            if(!visited[it] && dfs(it, edges, visited, node)){
                return true;
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && dfs(i, edges, visited, -1)){
                return true;
            }
            
        }
        return false;
    }
};