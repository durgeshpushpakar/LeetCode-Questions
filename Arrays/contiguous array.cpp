// https://leetcode.com/problems/contiguous-array/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int findMaxLength(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return 0;
    unordered_map<int, int>map;
    for(int i=0;i<n;i++)if(nums[i]==0)nums[i]=-1;    
    int sum=0;
    int maxLength=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum==0){
            maxLength=max(maxLength, i+1);
        }
        if(map.count(sum)==1)maxLength=max(maxLength, i-map[sum]);
        if(map.count(sum)!=1)map.insert(make_pair(sum, i));
    }
    return maxLength;
}
};
int main()
{

    return 0;
}