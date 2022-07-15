#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
int helper(int *wt, int *val, int n, int W, int idx){
    if(W==0)return 0;
    if(idx==n)return 0;
    int smallAns2=helper(wt, val, n, W, idx+1);
    if(wt[idx]<W){
        int smallAns1=helper(wt, val, n, W-wt[idx], idx+1);
        if(smallAns1>smallAns2)return val[idx]+smallAns1;
    }
    return smallAns2; 
}
int knapSack(int W, int wt[], int val[], int n){ 
    return helper(wt, val, n, W, 0);
}
};


int helper(int W, int *wt, int *val, int n, int i, vector<vector<int>>&arr){
        if(i==n){
            return 0;
        }
        if(arr[W][i]!=-1)return arr[W][i];
        int ans1=(wt[i]>W)?INT_MIN:val[i]+helper(W-wt[i], wt, val, n, i+1, arr);
        int ans2=helper(W, wt, val, n, i+1, arr);
        return arr[W][i]=max(ans1, ans2);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>arr(W+1, vector<int>(n+1, -1));
       return helper(W, wt, val, n, 0, arr);
    }
