#include<bits/stdc++.h>
using namespace std;
string fun(string s){
    string ans="";
    int len=s.length();
    for(int i=0;i<len;){
        int freq=1;
        char temp=s[i];
        int j=i+1;
        while(s[j]==temp){
            freq++;
            j++;
        }
        ans+=to_string(freq)+temp;
        i=j;
    }
    return ans;
}
string countAndSay(int n) {
    if(n==1)return "1";
    if(n==2)return "11";
    string smallAns=countAndSay(n-1);    
    return fun(smallAns);
}
int main()
{
    cout<<countAndSay(3);
    return 0;
}