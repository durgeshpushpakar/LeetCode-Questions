#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
bool isLucky(int n) {
    static int counter=2;
    if(counter>n)return true;
    if(n%counter==0)return false;
    n=n-(n/counter);
    counter++;
    return isLucky(n);    
}
int main(){

    return 0;
}