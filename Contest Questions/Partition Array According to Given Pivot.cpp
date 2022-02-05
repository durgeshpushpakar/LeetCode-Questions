// Partition Array According to Given Pivot
// https://leetcode.com/contest/biweekly-contest-71/problems/partition-array-according-to-given-pivot/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int>lessThan, equal, greaterThan;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<pivot)lessThan.push_back(nums[i]);
        else if(nums[i]>pivot)greaterThan.push_back(nums[i]);
        else equal.push_back(nums[i]);
    }   
    vector<int>ans;
    ans.insert(ans.end(), lessThan.begin(), lessThan.end() );
    ans.insert(ans.end(), equal.begin(), equal.end() );
    ans.insert(ans.end(), greaterThan.begin(), greaterThan.end() );
    return ans;
}
};
int main()
{

    return 0;
}