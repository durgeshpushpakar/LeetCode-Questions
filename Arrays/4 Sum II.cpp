#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int n=nums1.size();
    int ans=0;
    unordered_map<int, int>map;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[nums3[i]+nums4[j]]++;
            
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int reqSum = -1*(nums1[i]+nums2[j]);
            ans+=map[reqSum];
        }
    }
    return ans;
}
};
int main()
{

    return 0;
}