#include<bits/stdc++.h>
using namespace std;
int minCount(int n)
{
    if(n<=3)return n;
	vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=n;i++){
        int ans=INT_MAX;
        for(int j=1;j*j<=i;j++){
            ans=min(ans, 1+dp[i-(j*j)]);
        }
        dp[i]=ans;
    }
    return dp[n];
}
int main()
{
    
    return 0;
}