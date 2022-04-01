#include<bits/stdc++.h>
using namespace std;
int sqrt(int n){
    int low=1, high=n/2;
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)>>1;
        if((mid*mid)<=n){
            low=mid+1;
            ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    
    return 0;
}