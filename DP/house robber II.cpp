#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return nums[0];
    if(n==2)return max(nums[0], nums[1]);
    vector<int>dp1(nums.size());// without 0th index 
    vector<int>dp2(nums.size());// without last index
    dp1[1]=nums[1];
    dp1[2]=max(nums[1], nums[2]);
    for(int i=3;i<n;i++){
        dp1[i]=max(dp1[i-2]+nums[i], dp1[i-1]);
    }
    dp2[0]=nums[0];
    dp2[1]=max(nums[0], nums[1]);
    for(int i=2;i<n-1;i++){
        dp2[i]=max(dp2[i-2]+nums[i], dp2[i-1]);
    }
    return max(dp1[n-1], dp2[n-2]);
}
};
int main()
{

    return 0;
}