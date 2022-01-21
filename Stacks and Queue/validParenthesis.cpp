#include<bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string s){
    stack<char>st;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')st.push(s[i]);
        else if(st.empty())return false;
        else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(s[i]==')' && st.top()=='(')st.pop();
            else if(s[i]==']' && st.top()=='[')st.pop();
            else if(s[i]=='}' && st.top()=='{')st.pop();
            else return false;
        }
    }
    if(st.empty())return true;
    return false;
} // []{}()
int main()
{

    return 0;
}