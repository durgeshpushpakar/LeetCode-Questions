#include<bits/stdc++.h>
using namespace std;
int countWaysToMakeChange(int deno[], int n, int value){
    if(value==0)return 1;
    if(value<0)return 0;
    if(n<=0)return 0;
    int a=countWaysToMakeChange(deno, n, value-deno[0]);
    int b=countWaysToMakeChange(deno+1, n-1, value);
    return a+b;
}
//memoization
/*
int helper(int deno[], int n, int value, vector<vector<int>>&arr){
    if(value==0)return 1;
    if(value<0)return 0;
    if(n<=0)return 0;
    if(arr[n][value]!=-1)return arr[n][value];
    int a=helper(deno, n, value-deno[0], arr);
    int b=helper(deno+1, n-1, value, arr);
    arr[n][value]=a+b;
    return a+b;
}
int countWaysToMakeChange(int deno[], int n, int value){
    vector<vector<int>>arr(n+1 ,vector<int>(value+1, -1));
    return helper(deno, n, value, arr);
}
*/

// DP
int countWaysToMakeChange_DP(int deno[], int n, int value){
    vector<vector<int>>arr(n+1 ,vector<int>(value+1));
    // filling initial elements
    for(int i=0;i<=n;i++)
        arr[i][0]=1;
    for(int j=1;j<=value;j++)
        arr[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=value;j++){
            if(deno[n-i]>j)
                arr[i][j]=arr[i-1][j];
            else
                arr[i][j]=arr[i][j-deno[n-i]]+arr[i-1][j];
        }
    }
    return arr[n][value];
}
 
{
    int deno[3]={1,2,3};
    cout<<countWaysToMakeChange(deno, 3, 4);
    return 0;
}