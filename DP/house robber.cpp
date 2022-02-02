#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(vector<int>&arr, int i, vector<int>&dp){
    if(i>=arr.size())return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i]=max(helper(arr, i+1, dp), helper(arr, i+2, dp)+arr[i]);
    return dp[i];
}
int rob(vector<int>& nums) {
    vector<int>dp(nums.size(), -1);
    return helper(nums, 0, dp);
}
int rob_DP(vector<int>&nums){
    if(nums.size()==0)return 0;
    if(nums.size()==1)return nums[0];
    vector<int>dp(nums.size());
    dp[0]=nums[0];
    dp[1]=max(nums[1], nums[0]);
    for(int i=2;i<nums.size();i++){
        dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[nums.size()-1];
}
};
int main()
{
    Solution s;
    vector<int>arr{2,7,9,3,1,5,9,6,1,8};
    cout<<s.rob_DP(arr);
    return 0;
}