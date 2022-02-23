// https://leetcode.com/contest/weekly-contest-278/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> maxScoreIndices(vector<int>& nums) {
    vector<int> zerosTillI, onesRightToI;
    int count=0;
    zerosTillI.push_back(0);
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0)count++;
        zerosTillI.push_back(count);
    }
    count=0;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]==1)count++;
        onesRightToI.push_back(count);
    }
    reverse(onesRightToI.begin(), onesRightToI.end());
    onesRightToI.push_back(0);
    int dScore=0;
    vector<int>ans;
    unordered_map<int, vector<int>>umap;
    for(int i=0;i<=nums.size();i++){
        int score=zerosTillI[i]+onesRightToI[i];
        umap[score].push_back(i);
        dScore=max(dScore, score);
    }        
    return umap[dScore];
}
};
int main()
{

    return 0;
}