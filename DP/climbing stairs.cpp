#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

int helper(int n, vector<int>&dp) {
    if(n<=0)return 0;
    if(n==1 || n==2)return n;
    if(dp[n]!=-1)return dp[n];
    dp[n]=helper(n-1, dp)+helper(n-2, dp);
    return dp[n];
}
int climbStairs(int n)
{
    vector<int>dp(46, -1);
    return helper(n, dp);
}
};
int main()
{

    return 0;
}