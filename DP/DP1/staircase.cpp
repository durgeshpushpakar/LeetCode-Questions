#include<bits/stdc++.h>
using namespace std;
long staircaseDP(int n){
    long *arr= new long[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    long ans=arr[n];
    delete [] arr;
    return ans;
}
long helper(int n, long *arr){
    if(n<=0)return 1;
    if(n==1 || n==2)return n;
    if(n==3)return 4;
    if(arr[n]!=-1)return arr[n];
    long ans=helper(n-1, arr)+helper(n-2, arr)+helper(n-3, arr);
    arr[n]=ans;
    return arr[n];
}
long staircase(int n){
    long *arr= new long[n+1];
    memset(arr, -1, sizeof(arr));
    long ans=helper(n, arr);
    delete [] arr;
    return ans;
}

long staircase_rec(int n){
    if(n<=0)return 1;
    if(n==1 || n==2)return n;
    if(n==3)return 4;
    return staircase_rec(n-1)+staircase_rec(n-2)+staircase_rec(n-3);
}
int main(){
    cout<<staircase_rec(10);
    return 0;
}