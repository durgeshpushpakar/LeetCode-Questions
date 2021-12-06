#include<bits/stdc++.h>
using namespace std;
int solve(string s, string v) {
    int n=s.length();
    int m=v.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    vector<vector<int>>next(n+1, vector<int>(m+1));
    //filling the next array
    for(int i=0;i<n;i++){
        int prev=-1;
        for(int j=0;j<m;j++){
            if(s[i]=v[j])prev=j;
            next[i + 1][j + 1]=prev;
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=m;j++){
        dp[0][j]=INT_MAX;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(next[i][j]==-1)dp[i][j]=1;
            else{
                dp[i][j]=min(dp[i-1][j], dp[i-1][next[i][j]]+1);
            }
        }
    }
    return dp[n][m];
}
/*
MEMOIZATION FAILED
int helper(string a, string b, int siA, int siB, vector<vector<int>>dp) {
    if(siB==b.length())return 1;
    if(siA==a.length())return 1001;
    if(dp[siA][siB]!=-1)return dp[siA][siB];
    int option1=helper(a, b, siA+1, siB, dp);
    int indexB=-1;
    for(int i=0;i<b.length();i++){
        if(b[i]==a[siA]){
            indexB=i;
            break;
        }
    }
    if(indexB==-1){
        dp[siA][siB]=1;
        return 1;
    }
    int option2=1+helper(a, b, siA+1, indexB+1, dp);
    dp[siA][siB]=min(option1, option2);
    return dp[siA][siB];
}
int solve(string a, string b) {
    vector<vector<int>>dp(a.length(), vector<int>(b.length(), -1));
    return helper(a, b, 0, 0, dp);
} 
*/
int main()
{

    return 0;
}


/*
#include <vector>
int solve(string s, string v) {

// We establish the relationship between the sub problems and the
// problem at hand. Let dp(i, j) be the length of the shortest subsequence
// that is in s[1..i] that is not in v[1..j]. Here we have the following
// relationship: dp(i, j) = ...
// 1) If letter s[i] is nowhere to be found in v[1..j], then dp(i,j) = 1
// 2) Otherwise, we have two case:
// 2a) s[i] is in the shortest subsequence. We find k, the most
// immediate index in v[1..j] where v[k] == s[i].
// Then dp(i, j) = 1 + dp(i-1, k-1)
// 2b) s[i] is not in the shortest subsequence. Then dp(i, j) = dp(i-1, j)
// We pick whichever is lower.

int n = s.length();
int m = v.length();
vector<vector<int>> dp(n + 1, vector<int>(m + 1));
vector<vector<int>> next(n + 1, vector<int>(m + 1));
for (int i = 0; i < n; i++)
{
    int prev = -1;
    for (int j = 0; j < m; j++)
    {
        if (s[i] == v[j])
        {
            prev = j;
        }
        next[i + 1][j + 1] = prev;
    }
}
for (int i = 1; i <= n; i++)
{
    dp[i][0] = 1;
}
for (int i = 0; i <= m; i++)
{
    dp[0][i] = 1e9;
}
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= m; j++)
    {
        if (next[i][j] == -1)
        {
            dp[i][j] = 1;
        }
        else
        {
            dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][next[i][j]]);
        }
    }
}
return dp[n][m];
}
*/