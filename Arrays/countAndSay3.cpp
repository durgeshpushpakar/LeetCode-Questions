#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string say(string s){
    int len=s.length();
    string ans="";
    for(int i=0;i<len;i++){
        int count=1;
        while(i!=len-1 && s[i+1]==s[i]){
            count++;
            i++;
        }
        ans+=to_string(count)+s[i];
    }
    return ans;
}

string countAndSay(int n) {
    if(n==1)return "1";
    string smallAns=countAndSay(n-1);
    return say(smallAns);    
}
};
int main()
{

    return 0;
}