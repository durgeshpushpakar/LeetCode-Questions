#include<bits/stdc++.h>
using namespace std;
#define ll long long
int count(vector<int>&arr, int mid, int k){
    int cnt=1;
    int sum=0, j=1;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i]*(j++);
        if(sum>mid){
            cnt++;
            sum=arr[i];
            j=2;
        }
    }
    return cnt;
}
int solve(vector<int>&arr, int k){
    int n=arr.size();
    ll lo=INT_MAX, hi=0, j=1;
    for(ll x:arr){
        hi+=1LL*(j++)*x;
        lo=min(x, lo);
    }
    ll ans=-1;
    while(lo<=hi){
        ll mid=lo+((hi-lo)/2);
        cout<<"lo= "<<lo<<"hi= "<<hi<<" ";
        int temp=count(arr, mid, k);
        cout<<temp<<endl;
        if(temp<=k){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}
int main()
{
    vector<int>arr{1,2,3,4};
    cout<<solve(arr, 3);
    // cout<<count(arr, 9, 3);
    return 0;
}