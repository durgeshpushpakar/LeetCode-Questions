#include<bits/stdc++.h>
using namespace std;
int countBits(int n){
    // calculate nearest power of 2 of n
    // if n is 11
    if(n==0)return 0;
    int x=0;
    while((1<<x)<=n)x++;
    x--; // x is 3
    // can also use x=log2(n);
    int ans = (pow(2, x)/2)*x;
    ans += n - pow(2, x) + 1;
    ans += countBits(n - pow(2, x));
    return ans;
}