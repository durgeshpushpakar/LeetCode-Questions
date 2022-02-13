#include<bits/stdc++.h>
using namespace std;
/*
    **PRIORITY QUEUE APPROACH**

class Solution {
public:
int kthSmallest(vector<vector<int>>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>>minHeap;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            minHeap.push(arr[i][j]);
        }
    }    
    int temp=k-1;
    while(temp--){
        minHeap.pop();
    }
    return minHeap.top();
}
};
*/

/*BINARY SEARCH APPROACH*/
class Solution {
public:
int kthSmallest(vector<vector<int>>& arr, int k) {
    int n=arr.size();
    int low=arr[0][0];
    int high=arr[n-1][n-1];
    while(low<high){
        int mid=low + (high-low)/2;
        int count=0;
        for(int i=0;i<n;i++){
            count+= upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        }
        if(count<k){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;  
}
};
int main()
{

    return 0;
}