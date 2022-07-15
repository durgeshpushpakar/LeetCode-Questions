// https://www.interviewbit.com/problems/allocate-books/
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&arr, int mid, int B){
    int start=0, sum=0, n=arr.size(), student=1;
    for(int i=0;i<n;i++){
        if(arr[i]>mid)return false;
        if(sum+arr[i]<=mid)sum+=arr[i];
        else {
            student++;
            sum=arr[i];
        }
    }
    return student<=B;
}
int Solution::books(vector<int> &A, int B) {
    int low=INT_MAX, high=0, ans=-1;
    if(B>A.size())return -1;
    for(int x:A){
        high+=x;
        low=min(low, x);
    }
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(isPossible(A, mid, B)){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}
