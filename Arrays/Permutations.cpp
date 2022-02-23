// https://leetcode.com/problems/permutations/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>>ans;
void helper(int idx, vector<int>&temp){
    if(idx==temp.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=idx;i<temp.size();i++){
        swap(temp[idx], temp[i]);
        helper(idx+1, temp);
        swap(temp[idx], temp[i]);
    }
}
vector<vector<int>> permute(vector<int>& arr) {
    vector<int>temp=arr;
    helper(0, temp);
    return ans;
}
};
int main()
{

    return 0;
}