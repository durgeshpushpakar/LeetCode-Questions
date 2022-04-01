#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isValid(string s) {
    stack<int>st;
    for(char c:s){
        if(c==')' || c== ']' || c=='}'){
            if(st.empty())return false;
            if(c==')' && st.top()=='(')st.pop();
            else if(c==']' && st.top()=='[')st.pop();
            else if(c=='}' && st.top()=='{')st.pop();
            else return false;
        }
        if(c=='(' || c== '[' || c=='{'){
            st.push(c);
        }
    }    
    return st.empty();
}
};