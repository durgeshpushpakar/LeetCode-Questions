#include<bits/stdc++.h>
using namespace std;
int frogJumpK(vector<int>&arr, int n, int k){
    if(n==0)return 0;
    if(n==1)return 0; 
    vector<int>dp(n);
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=i-1; j>=0 && j>=i-k; j--){
            dp[i]=min(dp[i], dp[j]+abs(arr[i]-arr[j]));
        }
    }
    return dp[n-1];
}
int main()
{
    vector<int>arr;
    int n, k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr.push_back(a);
    }
    cout<<frogJumpK(arr, n, k);
    return 0;
}