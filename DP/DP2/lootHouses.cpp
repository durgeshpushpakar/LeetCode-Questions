#include<bits/stdc++.h>
using namespace std;
int helper(int *arr, int n, vector<int>&temp)
{
    if(n<=0 || arr==NULL)return 0;
    if(temp[n]!=-1)return temp[n];
    int a=helper(arr+1, n-1, temp);
    int b=helper(arr+2, n-2, temp)+arr[0];
    temp[n]=max(a, b);
    return temp[n];
}
int maxMoneyLooted(int *arr, int n){
    vector<int>temp(n+1, -1);
    return helper(arr, n, temp);
}
int maxMoneyLooted_DP(int *arr, int n){
    vector<int>temp(n+1);
    temp[0]=0;
    temp[1]=arr[n-1];
    for(int i=1;i<=n;i++){
        temp[i]=max(temp[i-1], temp[i-2]+arr[n-i]);
    }

    return temp[n];
}
