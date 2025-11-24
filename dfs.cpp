#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
        vis[node] = 1;
        ls.push_back(node);

        //traverse all its neighbours
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }
public:
    vector<int> dfsOfGraph(int n, vector<int> adj[]){
        int vis[n] = {0};
        int start = 0;

        vector<int> ls;  
        dfs(start, adj, vis, ls);

        return ls;
    }
};

// Creating adj
void CreateAdj(){
    int n;
    unordered_map<int, vector<int>> adj;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
}