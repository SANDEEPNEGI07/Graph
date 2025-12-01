// Disjoint Set Union

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int find(int i , vector<int> &parent){
        if(i == parent[i]){ // 'i' is the leader/parent of the set
            return i;
        }
        
        return find(parent[i], parent);
    }

    void Union(int x, int y, vector<int> &parent){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if(x_parent != y_parent){ 
            // They are not in the same set so we union them and take any one of them as a parent/leader.
            parent[x_parent] = y_parent;
        }
    }
};