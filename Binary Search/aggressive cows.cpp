// https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&arr, int mid, int c){
    int cows=1, prev=arr[0];
    int n=arr.size();
    for(int i=1;i<n;i++){
        if(arr[i]-prev>=mid){
            prev=arr[i];
            cows++;
        }
    }
    return cows>=c;
}

void solve(vector<int>&arr, int c){
    int n=arr.size(), low=1, high=arr[n-1]-arr[0];
    int ans=-1;
    while(low<=high){
        int mid=low+((high-low)>>1);
        if(isPossible(arr, mid, c)){
            low=mid+1;
            ans=mid;
        }
        else high=mid-1;
    }
    cout<<ans;
}
int main()
{
    int t;cin>>t;
    while(t--){
        int n,c;cin>>n>>c;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        solve(arr, c);
    }
    return 0;
}