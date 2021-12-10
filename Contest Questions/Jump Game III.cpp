#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool range(int i, int n){
    return (i>=0 && i<n);
}
bool helper(vector<int>&arr, int i, vector<bool>visited){
    int n=arr.size();
    if(!range(i, n))return false;
    if(visited[i])return false;
    if(arr[i]==0)return true;
    visited[i]=true;
    bool a=helper(arr, i-arr[i], visited);
    bool b=helper(arr, i+arr[i], visited);
    return a||b;
}
bool canReach(vector<int>& arr, int i) {
    vector<bool>visited(arr.size(), false);
    return helper(arr, i, visited);
}
};
int main()
{

    return 0;
}