#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto &e : prerequisites){
            int u = e[0], v = e[1];
            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }        
        }

        unordered_map<int, unordered_set<int>> mp;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it : adj[node]){
                mp[it].insert(node);

                //find the prerequisites of node as well and by transistivity, they are prerequisites of it. 
                for(auto &preq : mp[node]){
                    mp[it].insert(preq);
                }

                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        int Q = queries.size();
        vector<bool> result(Q, false);

        for(int i = 0; i < Q; i++){
            int src = queries[i][0];
            int dest = queries[i][1];

            bool reachable = mp[dest].contains(src);
            result[i] = reachable;
        }

        return result;
    }
};