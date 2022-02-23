#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>>ans;
void helper(vector<int>&arr, int si, int ei, int target, vector<int>temp){
    if(target<0)return;
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(si>ei)return;
    helper(arr, si+1, ei, target, temp);
    int i=1;
    while(arr[si]*i<=target){
        vector<int>temp2=temp;
        temp2.insert(temp2.end(), i, arr[si]);
        helper(arr, si+1, ei, target-(arr[si]*i), temp2);
        i++;
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n=candidates.size();
    vector<int>temp;
    helper(candidates, 0, n-1, target, temp);
}
};
int main()
{

    return 0;
}