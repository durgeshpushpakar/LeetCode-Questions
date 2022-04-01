#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll mod=1e9 +7;
int balancedBTs(int n) {
    if(n==0 || n==1)return 1;
    if(n==2)return 3;
    vector<ll>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=3;
    for(ll i=3;i<=n;i++){
        ll temp1=(dp[i-1]*dp[i-1])%mod;
        ll temp2=(((2*dp[i-1])%mod)*(dp[i-2]%mod))%mod;
        dp[i]=(temp1+temp2)%mod;
    }
    return dp[n];
}
int main()
{
    
    return 0;
}