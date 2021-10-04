#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> umap;
    for(int i=0;i<nums.size();i++){
        umap[nums[i]]++;
    }
    unordered_map<int, int>::iterator itr=umap.begin();
    for(;itr!=umap.end();itr++){
        if(itr->second!=1)return false;
    }
    return true;
}
int main()
{
    vector<int>arr;
    vector<int>::iterator itr=arr.begin();
    for(;itr!=arr.end();itr++){
        cout<<*itr;
    }
    for(auto itr:arr){
        cout<<itr;
    }
    return 0;
}