#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
int staircase(int n){
    if(n<=0)return 0;
    if(n==1 || n==2)return n;
    if(n==3)return 4;
    int a=staircase(n-1);
    int b=staircase(n-2);
    int c=staircase(n-3);
    return a+b+c;
}
int main(){

    return 0;
}