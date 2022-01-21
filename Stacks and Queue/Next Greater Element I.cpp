// https://leetcode.com/problems/next-greater-element-i/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
    stack<int>st;
    vector<int>ans(arr2.size());
    for (int i = arr2.size()-1; i >= 0; i--){
        if(st.empty()){
            ans[i]=-1;
        }
        else if(st.top()>arr2[i]){
            ans[i]=st.top();
        }
        else{
            while(!st.empty() && st.top()<=arr2[i])st.pop();
            if(st.empty()){
                ans[i]=-1;
            }
            else if(st.top()>arr2[i]){
                ans[i]=st.top();
            }
        }
        st.push(arr2[i]);
    }
    unordered_map<int, int>idx;
    for(int i=0;i<arr2.size();i++)idx[arr2[i]]=i;
    vector<int>ans2(arr1.size());
    for(int i=0;i<arr1.size();i++){
        ans2[i]=ans[idx[arr1[i]]];
    }
    return ans2;
}
};
int main()
{

    return 0;
}