#include <bits/stdc++.h>
using namespace std;
int balancedBTsDP(int n){
    long long mod = 1e9 + 7;
    vector<int>arr(n+1);
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        int temp1 = ((long long int)arr[i-1] * arr[i-1]) % mod;
        int temp2 = (2 * (long long int)arr[i-1] * arr[i-2]) % mod;
        int ans = (int)(((long long int)temp1 + temp2) % mod);
        arr[i]=ans;
    }
    return arr[n];
}
int helper(int n, vector<int> &arr)
{
    long long mod = 1e9 + 7;
    if (arr[n] != -1)
        return arr[n];
    int x=helper(n-1, arr);
    int y=helper(n-2, arr);
    long long int temp1 = ((long long int)x * x) % mod;
    long long int temp2 = (2 * (long long int)x * y) % mod;
    long long int ans = (temp1 + temp2) % mod;
    arr[n]=ans;
    return arr[n];
}
int balancedBTs_mem(int n)
{
    vector<int> arr(n + 1, -1);
    arr[0] = 1;
    arr[1] = 1;
    return helper(n, arr);
}
int balancedBTs(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int smallAns1 = balancedBTs(n - 1);
    int smallAns2 = balancedBTs(n - 2);
    return (smallAns1 * smallAns1) + (2 * smallAns1 * smallAns2);
}