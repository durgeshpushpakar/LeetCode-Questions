#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());
    int minDiff=INT_MAX;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-arr[i-1]<minDiff)minDiff=arr[i]-arr[i-1];
    }
    for(int i=1;i<arr.size();i++){
        if(arr[i]-arr[i-1]==minDiff)ans.push_back({arr[i-1], arr[i]});
    }
    return ans;
}
};
int main()
{

    return 0;
}