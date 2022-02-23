#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
//     }
// };
class Pair{
    public:
    int element, idx;
    Pair(int e, int i){
        element=e;
        idx=i; 
    }
};
vector<int> nextGreater(vector<int>arr){
    int n=arr.size();
    vector<int>ans;
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty())ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int>arr={3,2,6,9,8,11};
    vector<int>ans=nextGreater(arr);
    for(int x:ans)cout<<x<<" ";
    return 0;
}