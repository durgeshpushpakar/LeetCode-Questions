#include<bits/stdc++.h>
using namespace std;
int countSetBits(int n) {
    if(n<=0)return 0;
    if(n==1)return 1;
    int x=log2(n);
    return countSetBits(n-pow(2,x))+x*pow(2, x-1)+n-pow(2, x)+1;
}
int main()
{

    return 0;
}