/*
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int findMin(vector<int>& arr) {
    int n=arr.size();
    int low=0, high=n-1;
    while(low<high){
        int mid= low + ((high-low)>>1);
        if(arr[mid]<arr[high]){
            high=mid;
        }
        else low=mid+1;
    }
    return low;
}
};