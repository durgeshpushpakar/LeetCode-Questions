#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
/*
int sumOfAllSubarrays2(vector<int>&arr){
    int n=arr.size();
    int sum=0;
    long long ans=0;
    map<int, int>m;
    for(int len=2;len<=n;len++){
        // inserting first len elements
        for(int i=0;i<len;i++)m[arr[i]]++;
        auto mini=m.begin();
        auto maxi=m.end();
        maxi--;
        ans+=(maxi->first)-(mini->first);
        int l=0;
        for(int j=len ; j<n;j++){
            m[arr[l]]--;
            if(m[arr[l]]==0)m.erase(arr[l]);
            m[arr[j]]++;
            auto mini=m.begin();
            auto maxi=m.end();maxi--;
            ans+=(maxi->first)-(mini->first);
            l++;
        }   
    }
    return ans;
}
*/
/*
manas Solution
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll mod=1e9+7;
ll calc(vector<ll>&a,ll n){
     stack<pair<ll,ll>>st1;
         vector<ll>lmx(n,0),rmx(n,0);
         st1.push({0,-1});
         for(int i=0;i<n;i++)
         {
            while(st1.size()>1 &&st1.top().first>a[i])
            {
                st1.pop();
            }
            lmx[i]=i-st1.top().second;
            st1.push({a[i],i});
         }
         while(!st1.empty())
         {
             st1.pop();
         }
         st1.push({0,n});
         for(int i=n-1;i>=0;i--)
         {
            while(st1.size()>1 && st1.top().first>=a[i])
            {
                st1.pop();
            }
            rmx[i]=st1.top().second-i;
            st1.push({a[i],i});
         }
         while(!st1.empty())
         {
             st1.pop();
         }
         ll ans=0;
         for(int i=0;i<n;i++)
         {
             ans+=(a[i]*lmx[i]*rmx[i]);
         }
         return ans*-1;
}
int main() {
    // your code goes here;
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 ll t=1;
 //cin>>t;
 while(t--)
 {
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    b[i]=a[i]*-1;
    ll tm1=calc(a,n);
    
    ll tm2=calc(b,n);
    cout<<tm2+tm1; 
 }
}
*/
long long sumOfAllSubarrays(vector<int>&arr){
    int n=arr.size();
    int sum=0;
    long long ans=0;
    for(int i=0;i<n-1;i++){
        map<int, int>m;
        int maxi=arr[i], mini=arr[i];
        for(int j=i+1;j<n;j++){
            maxi=max(arr[j], maxi);
            mini=min(arr[j], mini);
            ans+=maxi-mini;
        }
    }
    return ans;
}



int main() {
    int n;cin>>n;
    vector<int>arr;
    while(n--){
        int a;cin>>a;
        arr.push_back(a);
    }
    cout<<sumOfAllSubarrays(arr);
    return 0;
}
