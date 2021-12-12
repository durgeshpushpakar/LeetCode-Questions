#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// dp[i][sum] contains whether we have a subset in i to n-1 of elements sum==sum
bool helper(vector<int>&arr, int i, int sum, vector<vector<int>>&dp){
    int n = arr.size();
    if(sum == 0)return true;
    if(sum < 0 || i==n)return false;
    if(dp[i][sum]!=-1)return (bool)dp[i][sum];
    dp[i][sum]=helper(arr, i+1, sum-arr[i], dp)||helper(arr, i+1, sum, dp);
    return (bool)dp[i][sum];
}
bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++)sum+=nums[i];
    if(sum%2==1)return false;
    sum/=2;
    vector<vector<int>>dp(nums.size()+1, vector<int>(sum+1, -1));
    return helper(nums, 0, sum, dp);    
}
};
int main()
{

    return 0;
}