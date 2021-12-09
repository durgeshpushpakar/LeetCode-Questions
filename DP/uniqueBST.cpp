#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int helper(int n, vector<int>&arr){
    if(n==1 ||n==0)return 1;
    if(arr[n]!=-1)return arr[n];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=helper(i-1, arr)*helper(n-i, arr);
    }
    arr[n]=ans;
    return ans;
}
int numTrees(int n) {
    vector<int>arr(n+1, -1);
    return helper(n, arr);
}
int numTrees_DP(int n){
    vector<int>arr(n+1);
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        int ans=0;
        for(int j=1;j<=i;j++){
            ans+=arr[j-1]*arr[i-j];
        }
        arr[i]=ans;
    }
    return arr[n];
}
};
int main()
{
    Solution s;
    cout<<s.numTrees_DP(10);
    return 0;
}