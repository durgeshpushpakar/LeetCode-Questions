#include<bits/stdc++.h>
using namespace std;
int firstOcc(vector<int>arr, int x){
    int n=arr.size();
    int low=0, high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid]==x){
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]>x)high=mid-1;
        else low = mid+1;
    }
    return ans;
}
int main()
{
    vector<int>arr{1,2,5,5,6,7};
    cout<<firstOcc(arr, 6);
    return 0;
}