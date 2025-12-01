//990. Satisfiability of Equality Equations

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(i == parent[i]) return i;

        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return ;

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] > rank[x_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            // rank of x and y is equal
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(string &s : equations){
            if(s[1] == '='){ // "a==b"
                Union(s[0] - 'a', s[3] - 'a');
            }
        }

        for(string &s : equations){
            if(s[1] == '!'){ // "a!=b"
                char first = s[0];
                char second = s[3];

                int first_parent = find(first - 'a');
                int second_parent = find(second - 'a');

                if(first_parent == second_parent) return false;
            }
        }
        return true;
    }
};