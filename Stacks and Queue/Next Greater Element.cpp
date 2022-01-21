// https://leetcode.com/problems/next-greater-element-ii/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> nextGreaterElements(vector<int>& arr) {
    vector<int>arr2(arr.begin(), arr.end());
    for(int i=0;i<arr.size();i++)arr2.push_back(arr[i]);
    stack<int>st;
    vector<int>ans(arr2.size());
    for(int i = arr2.size()-1; i >= 0; i--){
        if(st.empty())ans[i]=-1;
        else if(st.top()>arr2[i])ans[i]=st.top();
        else{
            while(!st.empty() && arr2[i]>=st.top())st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
        }
        st.push(arr2[i]);
    }
    vector<int>ans2(ans.begin(), ans.begin()+arr.size());
    return ans2;
}
};
int main()
{

    return 0;
}