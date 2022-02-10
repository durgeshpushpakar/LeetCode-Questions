#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return 1;
    if(n==0)return 0;
    vector<int>dp(n);
    dp[0]=1;
    dp[1]=(nums[0]<nums[1])?2:1;
    int maxAns=max(dp[0], dp[1]);
    for(int i=2;i<n;i++){
        int temp=1;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i]){
                temp=max(temp, dp[j]+1);
            }
        }
        dp[i]=temp;
        maxAns=max(maxAns, dp[i]);
    }
    return dp[n-1];
}
};
int main()
{

    return 0;
}