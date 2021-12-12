#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> searchRange(vector<int>& arr, int k) {
    int n=arr.size();
    vector<int>ans;
    int leftIdx=-1;
    int left=0, right=n-1;
    while(right>=left){
        int mid=(right+left)/2;
        if(arr[mid]<k)left=mid+1;
        else if(arr[mid]>k)right=mid-1;
        else {
            right=mid-1;
            leftIdx=mid;
        }
    }
    left=0;right=n-1;
    int rightIdx=-1;
    while(right>=left){
        int mid=(right+left)/2;
        if(arr[mid]<k)left=mid+1;
        else if(arr[mid]>k)right=mid-1;
        else if(arr[mid]==k){
            left=mid+1;
            rightIdx=mid;
        }
    }
    ans.push_back(leftIdx);
    ans.push_back(rightIdx);
    return ans;
}
};
int main()
{

    return 0;
}