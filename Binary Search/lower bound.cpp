#include<bits/stdc++.h>
using namespace std;
int lowerbound(vector<int>arr, int x){
    int n=arr.size();
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr{1,2,5,5,6,7};
    cout<<lowerbound(arr, 5);
    return 0;
}