// DSU using path compression for find and Rank for union funtion.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int find(int i , vector<int>& parent){
        if(i == parent[i]){
            return i;
        }

        return parent[i] = find(parent[i], parent); // Storing the leader of the same set to all the element of that set.
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        
        // parent are same both x and y belongs to the same set
        if(x_parent == y_parent) return ;

        // rank of x set is greater
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }

        if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }

        // both rank of x set and y set is equal.
        else{
            parent[y_parent] = x_parent;
            rank[x_parent]++; //increase the rank of the x set leader.
        }
    }
};