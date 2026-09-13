#include <bits/stdc++.h>

using namespace std;
class DSU{
    public:
    vector<int>parent, rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    void unionn(int u, int v){
        v=getParent(v);
        u=getParent(u);
        if(u==v)return;
        if(rank[v]==rank[u]){
            parent[u]=v;
            rank[v]++;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else{
            parent[v]=u;
        }
    }
    int getParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=getParent(parent[u]);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        DSU dsu(n);
        // map mails->index
        unordered_map<string, int>mailToIdx;
        for(int i=0;i<n;i++){
            string name=acc[i][0];
            for(int j=1;j<acc[i].size();j++){
                if(mailToIdx.count(acc[i][j])==1){
                    // mail already there so add this to the same component
                    dsu.unionn(mailToIdx[acc[i][j]], i);
                }
                else{
                    mailToIdx[acc[i][j]]=i;
                }
            }
        }
        unordered_map<int, unordered_set<string>>ans;
        for(int i=0;i<n;i++){
            int x=dsu.getParent(i);
            if(ans.contains(x)){
                for(int j=1;j<acc[i].size();j++){
                    ans[x].insert(acc[i][j]);
                }
            }
            else{
                for(int j=1;j<acc[i].size();j++){
                    ans[x].insert(acc[i][j]);
                }
            }
        }
        //map index->map_of_mails
        vector<vector<string>>ans2;
        for(int i=0;i<n;i++){
            if(ans.contains(i)){
                vector<string>temp;
                temp.push_back(acc[i][0]);
                for(string x:ans[i]){
                    temp.push_back(x);
                }
                auto itr=temp.begin();itr++;
                sort(itr, temp.end());
                ans2.push_back(temp);
            }
        }
        // map index(parent)->map of mails
        return ans2;
    }
};
int main() {

    
    return 0;
}