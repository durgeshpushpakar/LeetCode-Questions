#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int jump(vector<int>& nums) {
    int n=nums.size();
    if(n==0)return 0;
    if(n==1)return 0;
    vector<int>dp(n);
    dp[0]=0;
    dp[1]=(nums[0]!=0) ? 1 : 0;
    for(int i=2;i<n;i++){
        int minJumps=INT_MAX;
        for(int j=i-1;j>=0;j--){
            if(nums[j]>=i-j){
                minJumps=min(minJumps, dp[j]+1);
            }
        }
        dp[i]=minJumps;
    }
    return dp[n-1];
}
};
int main()
{

    return 0;
}