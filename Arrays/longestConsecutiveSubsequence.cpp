// https://leetcode.com/problems/longest-consecutive-sequence/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    unordered_set<int>umap;
    for(int i=0;i<nums.size();i++){
        umap.insert(nums[i]);
    }
    int maxConsec=0;
    for(int i=0;i<nums.size();i++){
        int count=1;
        int element=nums[i]+1;
        if(umap.count(nums[i]-1)==1)continue;
        while(umap.count(element)==1){
            element++;
            count++;
        }
        maxConsec=max(maxConsec, count);
    }
    return maxConsec;
}


};
int main()
{

    return 0;
}