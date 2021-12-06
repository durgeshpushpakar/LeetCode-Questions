#include<bits/stdc++.h>
using namespace std;
int helper(int a, int b, int k) {
    if(a==0)return 1;
    int ans=0;
    for(int i=k+1;pow(i,b)<=a;i++){
        ans+=helper(a-pow(i, b), b, i);
    }
    return ans;
}
int getAllWays(int a, int b){
    return helper(a, b, 0);
}
int main()
{
    cout<<getAllWays(100, 2);
    return 0;
}