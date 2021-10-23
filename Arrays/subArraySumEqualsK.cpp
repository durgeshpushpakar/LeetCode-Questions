// https://leetcode.com/problems/subarray-sum-equals-k/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int>mp;
    int prefixSum=0;
    int count=0;
    for(int i=0;i<nums.size();i++){
        prefixSum+=nums[i];
        if(prefixSum==k)count++;
        else if(mp.count(prefixSum-k)==1){
            count+=mp[prefixSum-k];
        }
        mp[prefixSum]++;
    }  
    return count;
}
};
int main()
{

    return 0;
}