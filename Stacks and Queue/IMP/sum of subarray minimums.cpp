// https://leetcode.com/problems/sum-of-subarray-minimums/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
long mod=1e9+7;
vector<int>lessThanLeft(vector<int>&arr){
    int n=arr.size();
    vector<int>ans;
    stack<pair<int, int>>st;
    st.push({arr[0], 1});
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first>=arr[i])st.pop();
        if(st.empty()){
            st.push({arr[i], i+1});
            ans.push_back(i+1);
        }
        else {
            ans.push_back(st.top())
        }        
    }
}
int sumSubarrayMins(vector<int>& arr) {
       
}
};