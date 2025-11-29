#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree){
        queue<int> q;

        int count = 0;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    count++;
                    q.push(it);
                }
            }
        }
        if(count == n){ //count==n means i was able to visit all courses
            return true;
        } 
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &e : prerequisites){
            int u = e[0], v = e[1];

            // v ---> u
            adj[v].push_back(u);
            indegree[u]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};