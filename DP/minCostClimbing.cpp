// https://leetcode.com/problems/min-cost-climbing-stairs/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int minCostHelper(vector<int>&arr, vector<int>&dp, int i){
    int n=arr.size();
    if(i>=n)return 0;
    if(i==n-1 || i==n-2)return arr[i];
    if(dp[i]!=-1)return dp[i];
    dp[i]=min(minCostHelper(arr, dp, i+1), minCostHelper(arr, dp, i+2))+arr[i];
    return dp[i];
}
int minCostClimbingStairs(vector<int>& cost) {
    vector<int>dp(cost.size()+1, -1);
    vector<int>dp2(cost.size()+1, -1);
    return min(minCostHelper(cost, dp, 0), minCostHelper(cost, dp2, 1));
}
};
int main()
{

    return 0;
}
