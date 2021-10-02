#include<bits/stdc++.h>
using namespace std;
string fun(string s){
    int len=s.length();
    string ans="";
    for(int i=0;i<len;i++){
        int freq=1;
        if(s[i+1]==s[i]){
            for(int j=i+1;j<len;j++){
                if(s[j]==s[i]){
                    freq++;
                    if(j==len-1){
                        ans+=to_string(freq)+s[j];
                        return ans;
                    }
                }
                else if(s[j]!=s[i]){
                    ans+=to_string(freq)+s[i];
                    i=j-1;
                    break;
                }
            }
        }
        else{
            ans+=to_string(1)+s[i];
        }
    }
    return ans;
}
string countAndSay(int n) {
    if(n==1)return "1";
    if(n==2)return "11";
    string smallAns=countAndSay(n-1);   
    return fun(smallAns);
}

int main(){
    cout<<countAndSay(15);
    return 0;
}