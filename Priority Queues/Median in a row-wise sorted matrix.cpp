#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
int median(vector<vector<int>> &arr, int r, int c){
    int low=INT_MAX, high=INT_MIN;
    for(int i=0;i<r;i++){
        low=min(low, arr[i][0]);
        high=max(high, arr[i][c-1]);
    }
    // maximum element = high  
    // minimum element = low
    int k=r*c/2;
    while(low<high){
        int mid=low + (high-low)/2;
        int count=0;
        for(int i=0;i<r;i++){
            count += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        }
        if(count>k)high=mid;
        else low=mid+1;
    }
    return low;
}
};
int main()
{

    return 0;
}