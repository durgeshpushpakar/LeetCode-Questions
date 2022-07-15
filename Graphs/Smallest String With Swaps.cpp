// https://leetcode.com/problems/smallest-string-with-swaps/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void unionn(vector<int>&parent, vector<int>&rank, int u, int v){
    if(rank[u]==rank[v]){
        parent[u]=v;
        rank[v]++;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else parent[u]=v;
}
int find(vector<int>&parent, int u){
    if(parent[u]==u)return u;
    return parent[u]=find(parent, parent[u]);
}
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n=s.length();
    vector<int>parent(n), rank(n, 0);
    for(int i=0;i<n;i++)parent[i]=i;
    for(auto &x:pairs){
        unionn(parent, rank, x[0], x[1]);
    }
    string ans(n, ' ');
    unordered_map<int, vector<int>>umap;
    for(int i=0;i<n;i++){
        int par=find(parent, i);
        umap[par].push_back(i);      
    }
    for(auto itr=umap.begin();itr!=umap.end();itr++){
        string temp="";
        for(int x:itr->second){
            temp+=s[x];
        }
        sort(temp.begin(), temp.end());
        int i=0;
        for(int x:itr->second){
            ans[x]=temp[i++];
        }
    }
    return ans;
}
};