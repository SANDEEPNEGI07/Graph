#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    
    void dfs(int node, vector<vector<int>>& adj, vector<bool> &visited, stack<int> &st){
        visited[node] = true;
        
        // first children will be pushed to the stack
        for(auto &it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited, st);
            }
        }
        
        // After loop finishes for node then node will be pushed to the stack
        st.push(node);
        
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto &e : edges){
            int u = e[0], v= e[1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, st);
            }
        }
        vector<int> result;
        
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            
            result.push_back(ele);
        }
        
        return result;
    }
};
