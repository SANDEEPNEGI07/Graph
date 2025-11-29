#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto &e : prerequisites){
            int u = e[0], v = e[1];
            adj[v].push_back(u);

            indegree[u]++;
        }
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> result;
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
        return (result.size() == numCourses) ? result : vector<int>();
    }
};