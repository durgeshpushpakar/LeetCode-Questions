#include<bits/stdc++.h>
using namespace std;
int minCountDP(int n){
    vector<int>arr(n+1);
    arr[0]=0;arr[1]=1;
    for(int i=2;i<=n;i++){
        int minimum=INT_MAX;
        for(int j=1;j<=sqrt(i);j++){
            minimum=min(minimum, arr[i-(j*j)]);
        }
        arr[i]=minimum+1;
    }
    return arr[n];
}
int helper(int n, vector<int>&arr){
    if(arr[n]!=-1)return arr[n];
    int minimum=INT_MAX;
    for(int i=1;i<=sqrt(n);i++)minimum=min(minimum, minCount(n-(i*i)));
    arr[n]=minimum+1;
    return arr[n];
}
int minCount_mem(int n){
    vector<int>arr(n+1, -1);
    arr[0]=0;
    arr[1]=1;
    return helper(n, arr);
}
int minCount(int n){
    if(n<=0)return 0;
    if(n==1)return 1;
    int minimum=INT_MAX;
    for(int i=1;i<=sqrt(n);i++){
        minimum=min(minimum, minCount(n-(i*i)));
    }
    return minimum+1;
}
int main()
{
    cout<<minCountDP(9);
    return 0;
}