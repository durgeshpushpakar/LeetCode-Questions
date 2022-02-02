#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool binarySearch(vector<int>arr, int x){
    int i=0, j=arr.size()-1; 
    int mid;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]==x)return true;
        if(arr[mid]>x)j=mid-1;
        else i=mid+1;
    }
    return false;
}
int findFinalValue(vector<int>& nums, int original) {
    sort(nums.begin(), nums.end());
    while(1){
        if(binarySearch(nums, original))original*=2;
        else return original;
    }
    return original;
}
};
int main()
{

    return 0;
}