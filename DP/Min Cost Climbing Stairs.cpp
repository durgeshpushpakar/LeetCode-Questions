// https://leetcode.com/problems/min-cost-climbing-stairs/ 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(vector<int>&cost, int i, vector<int>dp){
    if(i==0 || i==1)return cost [i];
    if(dp[i]!=-1)return dp[i];
    int x=helper(cost, i-2, dp);
    int y=helper(cost, i-1, dp);
    dp[i]=min(x, y) + cost[i];;
    return dp[i]; 
}   
int minCostClimbingStairs(vector<int>& cost) {
    vector<int>dp(cost.size(), -1);
    return min(helper(cost, cost.size()-1, dp), helper(cost, cost.size()-2, dp));    
}
};
int main()
{

    return 0;
}