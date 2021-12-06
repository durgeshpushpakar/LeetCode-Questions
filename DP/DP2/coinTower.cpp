#include<bits/stdc++.h>
using namespace std;
string findWinner(int n, int x, int y)
{
    if(x>y)swap(x,y);
    vector<bool>dp(n+1, -1);
    dp[0]=true;
    for(int i=1;i<=n;i++){
        if(i==x || i==y || i==1){
            dp[i]=true;
        }
        else if(i<x){
            dp[i]=!dp[i-1];
        }
        else if(i<y){
            dp[i]=(!dp[i-1] || !dp[i-x]);
        }
        else{
            dp[i]=(!dp[i-1] || !dp[i-x] || !dp[i-y]);
        }
    }
    if(dp[n])return "Beerus";
    return "Whis";
}
int main()
{

    return 0;
}