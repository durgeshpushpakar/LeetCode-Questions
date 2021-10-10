// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
#include<bits/stdc++.h>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    vector<int>ans;
    if(nums1.size()==0){
        ans=nums2;
        return ans;
    }
    if(nums2.size()==0){
        ans=nums1;
        return ans;
    }
    unordered_map<int, int> umap2;
    for(int i=0;i<nums1.size();i++){
        umap2[nums2[i]]++;
    }
    for(int i=0;i<nums1.size();i++){
        int temp=nums1[i];
        if(umap2[temp]>=1){
            ans.push_back(temp);
            umap2[temp]--;
        }
    }
    return ans;
}
int main()
{
    vector<int>ans{10,20,30};
    ans.insert(ans.begin()+2, 3, 40);
    for(auto it:ans)cout<<it<<" ";
    return 0;
}