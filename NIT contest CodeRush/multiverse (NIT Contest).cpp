#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*
//Ordered Set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
*/
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


