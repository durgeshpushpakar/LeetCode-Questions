#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>NLR(vector<int>arr){
    vector<int>ans;
    int n=arr.size();
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty())ans.push_back(n);
        else if(arr[st.top()]>=arr[i]){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(st.empty())ans.push_back(n);
            else ans.push_back(st.top());
        }
        else{
            ans.push_back(st.top());
        }

        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int>NLL(vector<int>arr){
    vector<int>ans;
    int n=arr.size();
    stack<int>st;
    for(int i=0;i<n;i++){
        if(st.empty())ans.push_back(-1);
        else if(arr[st.top()]>=arr[i]){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(st.empty())ans.push_back(-1);
            else ans.push_back(st.top());
        }
        else{
            ans.push_back(st.top());
        }
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    vector<int>left=NLL(heights);   
    vector<int>right=NLR(heights);
    int maxArea=0;
    for(int i=0;i<left.size();i++){
        int area = heights[i]*(right[i]-left[i]-1);
        maxArea=max(area, maxArea);
    }
    return maxArea;
}
};
int main()
{
    Solution s;
    vector<int>arr{2,1,5,6,2,3};
    cout<<s.largestRectangleArea(arr)<<endl;
    vector<int>ans=s.NLR(arr);
    for(auto itr:ans)cout<<itr<<" ";
    return 0;
}