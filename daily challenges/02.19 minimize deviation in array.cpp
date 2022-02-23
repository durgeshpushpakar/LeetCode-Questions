// https://leetcode.com/problems/minimize-deviation-in-array/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int minimumDeviation(vector<int>& arr) {
    int n=arr.size();
    priority_queue<int>pq;
    int mn=INT_MAX, mx=INT_MIN;
    int diff=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]%2==1)arr[i]=2*arr[i];
        mn=min(mn, arr[i]);
        pq.push(arr[i]);
    }
    while(pq.top()%2==0){
        int element=pq.top();
        diff=min(diff, element-mn);
        mn=min(element/2, mn);
        pq.pop();
        pq.push(element/2);
    }
    return min(diff, pq.top()-mn);
}
};