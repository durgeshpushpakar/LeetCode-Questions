#include<bits/stdc++.h>
using namespace std;

// make a dp array and dp[i] will contain the minimum enery used to reach i
int frogJump(int n, vector<int> &arr)
{   
    vector<int>dp(n);
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]), dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    // for(int x:dp)cout<<x<<" ";
    // cout<<endl<<endl;
    return dp[n-1];
}
int main()
{
    vector<int>arr{10,20,30,10};
    cout<<frogJump(4, arr);
    return 0;
}