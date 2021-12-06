#include<bits/stdc++.h>
using namespace std;
int helper(int* arr, int si, int ei, vector<vector<int>>&dp){
    if(ei-si<=1)return 0; //check
    int ans=INT_MAX;
    for(int i=si+1;i<ei;i++){
        int a=helper(arr, si, i, dp);
        int b=helper(arr, i, ei, dp);
        ans=min(ans, a+b+arr[i]*arr[si]*arr[ei]);
    }
    return ans;
}
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>>dp(n, vector<int>(n+1, -1));
    return helper(arr, 0, n, dp);
}
int main()
{

    return 0;
}