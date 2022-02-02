// https://leetcode.com/problems/delete-and-earn/
/*
[2,2,3,3,3,4]
[1,2,3,4,5,6,7,8,9]
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

int deleteAndEarn(vector<int>& nums) {
    int i=0;
    vector<int>freq(10001, 0);
    int inc=0, exc=0;
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
    }
    for(int i=1;i<freq.size();i++){
        int include=inc, exclude=exc;
        inc=exclude+(freq[i]*i);
        exc=max(include, exclude);
    }
    return max(inc, exc);
}
};
int main()
{
    Solution s;
    vector<int>arr{2,2,3,3,3,4};
    cout<<s.deleteAndEarn(arr);
    return 0;
}