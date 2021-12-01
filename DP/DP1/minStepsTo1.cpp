#include<bits/stdc++.h>
using namespace std;
int helper(int n, int *arr){
    if(n==1)return 0;
    if(arr[n]!=-1)return arr[n];
    int smallAns1=INT_MAX, smallAns2=INT_MAX, smallAns3=INT_MAX;
    smallAns1=helper(n-1, arr);
    if(n%2==0)smallAns2=helper(n/2, arr);
    if(n%3==0)smallAns3=helper(n/3, arr);
    arr[n]=min(smallAns1, min(smallAns2, smallAns3))+1;
    return arr[n];
}
int countMinStepsToOne(int n)
{
    int arr[n+1];
    memset(arr, -1, sizeof(arr));
    arr[0]=0;arr[1]=0;
    return helper(n, arr);
}
int countDP(int n){
    int arr[n+1];
    arr[0]=0;arr[1]=0;
    for(int i=2;i<=n;i++){
        int temp1=INT_MAX, temp2=INT_MAX, temp3=INT_MAX;
        temp1=1+arr[i-1];
        if(i%2==0)temp2=1+arr[n/2];
        if(i%3==0)temp3=1+arr[n/3];
        arr[i]=min(temp1, min(temp2, temp3));
    }
    return arr[n];
}