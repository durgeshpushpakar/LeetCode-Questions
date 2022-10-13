class Solution {
public:
    vector<int>dp;
    int helper(vector<int>&nums, int i){
        int n=nums.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(helper(nums, i+1), nums[i]+helper(nums, i+2));
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return helper(nums, 0);
    }
};