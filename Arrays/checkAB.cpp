#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
bool checkAB(char input[]) {
    if(strlen(input)<=0)return true;
    if(input[0]=='a'){
        if(input[1]=='b' && input[1]=='b')return checkAB(input+3);
        if(input[1]=='a')return checkAB(input+1);
        if(input[1]=='\0')return true;
        return false;
    }
    return false;
}
int reverse(int n){
    int k=n;
    int ans=0;
    while(k>0){
        int mod=k%10;
        cout<<"mod= "<<mod<<endl;
        ans+=(ans*10)+mod;
        cout<<"ans= "<<ans<<endl;
        k/=10;
    }
    if(ans>=INT_MAX)return 0;
    return ans;
}
int main(){

    return 0;
}