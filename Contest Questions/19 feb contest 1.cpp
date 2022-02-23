#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int countPairs(vector<int>& arr, int k) {
    int n=arr.size();
    int ans=0;
    unordered_map<int, vector<int>>umap;
    for(int i=0;i<n;i++){
        if(umap.count(arr[i])){
            vector<int>temp=umap[arr[i]];
            for(int j=0;j<temp.size();j++){
                if(i*temp[j]%k==0)ans++;
            }
        }
        umap[arr[i]].push_back(i);
    }   
    return ans;
}
};