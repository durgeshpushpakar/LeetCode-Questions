#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>> helper(vector<int>&arr, int idx){
    if(idx==arr.size()){
        vector<vector<int>>ans(1);
        return ans;
    }
    vector<vector<int>>ans1=helper(arr, idx+1);
    int size=ans1.size();
    for(int i=0 ; i<size ; i++){
        vector<int>temp;
        temp.push_back(arr[idx]);
        for(int j=0;j<ans1[i].size();j++){
            temp.push_back(ans1[i][j]);
        }
        ans1.push_back(temp);
    }
    return ans1;
}
vector<vector<int>> subsets(vector<int>& nums) {
    return helper(nums, 0);    
}
};
int main()
{

    return 0;
}