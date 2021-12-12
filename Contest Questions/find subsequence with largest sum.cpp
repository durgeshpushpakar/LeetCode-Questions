// length k and largest sum 
#include<bits/stdc++.h>
using namespace std;

//DP Solution
/*
class Pair{
    public:
    int sum;
    vector<int>ans;
    Pair(int s, vector<int>v){
        sum=s;
        ans=v;
    }
};
class Solution {
public:
Pair helper(vector<int>&arr, int i, int k, vector<vector<Pair>>&dp){
    vector<int>ans;
    if(k==0){
        Pair output(0, ans);
        return output;
    }
    if(i==arr.size()){
        Pair output(INT_MIN, ans);
        return output;
    }
    if(dp[i][k].sum!=INT_MAX)return dp[i][k];
    Pair ans1=helper(arr, i+1, k-1, dp);
    Pair ans2=helper(arr, i+1, k, dp);
    if(ans1.sum!=INT_MIN && ans1.sum+arr[i]>ans2.sum){
        ans1.sum+=arr[i];
        ans1.ans.insert(ans1.ans.begin(), arr[i]);
        dp[i][k]=ans1;
        return ans1;
    }
    else{
        dp[i][k]=ans2;
        return ans2;
    }
}
vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int>x;
    Pair temp(INT_MAX, x);
    vector<vector<Pair>>dp(nums.size()+1, vector<Pair>(k+1, temp));
    return helper(nums, 0, k, dp).ans;    
}
};
*/
class Solution {
public:
int find_min(vector<int>&arr){
    int idx=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<arr[idx])idx=i;
    }
    return idx;
}
vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int>ans;
    for(int i=0;i<k;i++)ans.push_back(nums[i]);
    for(int i=k;i<nums.size();i++){
        int idx=find_min(ans);
        if(nums[i]>ans[idx]){
            ans.push_back(nums[i]);
            ans.erase(ans.begin()+idx);
        }
    }
    return ans;
}
};
int main()
{

    return 0;
}