// Also known as Kahn's Algorithm - topological sort using BFS

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges){
        vector<int> result; // To store the output

        // Adj list
        unordered_map<int, vector<int>> adj;
        for(auto &e : edges){
            int u = e[0], v = e[1];

            adj[u].push_back(v);
        }

        // Step 1 - store indegree of each element
        vector<int> indegree(V, 0);
        for(int u = 0; u < V; u++){
            for(int &v : adj[u]){
                indegree[v]++;
            }
        }

        // Step 2 - Push node with indegree 0 to queue
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // Step 3 - Simple BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto &it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return result;
    }
};