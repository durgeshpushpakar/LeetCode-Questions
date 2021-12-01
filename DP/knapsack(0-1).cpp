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
