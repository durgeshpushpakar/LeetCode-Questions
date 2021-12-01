#include<bits/stdc++.h>
using namespace std;
int fib(int n, int *ans){
    if(n<=1)return 1;
    if(ans[n]!=-1)return ans[n];
    int temp=fib(n-1, ans)+fib(n-2, ans);
    ans[n]=temp;
    return temp;
}
int main()
{
    int n=5;
    int ans[n+1];
    memset(ans, -1, sizeof(ans));
    ans[0]=1;ans[1]=1;

    cout<<fib(n, ans);
    
    return 0;
}