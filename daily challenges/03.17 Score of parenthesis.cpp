#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int scoreOfParentheses(string s) {
    stack<char>st;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){
            ans+=pow(2, st.size()-1);
            while(i<s.length() && s[i]==')'){
                i++;
                st.pop();
            }xz
            if(s[i]=='(')i--;
            else break;
        }
    }    
    return ans;
}
};