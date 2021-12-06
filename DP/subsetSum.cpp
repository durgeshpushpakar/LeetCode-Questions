// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
/*
bool helper(int N, int arr[], int sum, vector<vector<int>>&dp){
    if(sum==0)return true;
    if(sum<0)return false;
    if(N==0)return false;
    if(dp[N][sum]!=-1)return (bool)dp[N][sum];
    dp[N][sum]=(int)(helper(N-1, arr+1, sum-arr[0], dp)||helper(N-1, arr+1, sum, dp));
    return (bool)(dp[N][sum]);
}
bool isSubsetSum(int N, int arr[], int sum){
    vector<vector<int>>dp(N+1, vector<int>(sum+1, -1));
    return helper(N, arr, sum, dp);
}
*/
bool isSubsetSum(int n, int *arr, int sum){
    vector<vector<bool>>dp(n+1, vector<bool>(sum+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int j=1;j<=sum;j++){
        dp[0][j]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[n-i]>j)
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=dp[i-1][j-arr[n-i]] || dp[i-1][j];
        }
    }
    return dp[n][sum];
}
};
int main()
{

    return 0;
}