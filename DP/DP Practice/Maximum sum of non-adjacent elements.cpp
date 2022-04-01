#include<bits/stdc++.h>
using namespace std;
int maximumNonAdjacentSum(vector<int> &arr){
    int n=arr.size();
    vector<int>dp(n);
    if(n==0)return 0;
    if(n==1)return arr[0];
    if(n==2)return max(arr[0], arr[1]);
    // dp[0]=arr[0];
    // dp[1]=max(arr[0], arr[1]);
    int prev=max(arr[0], arr[1]);
    int prev2=arr[0];
    for(int i=2;i<n;i++){
        dp[i]=max(arr[i]+prev2, prev);
        prev2=prev;
        prev=dp[i];
    }
    return dp[n-1];
}
int main()
{
    
    return 0;
}