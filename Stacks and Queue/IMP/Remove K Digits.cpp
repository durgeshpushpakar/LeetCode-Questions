#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string removeKdigits(string num, int k) {
    stack<char>st;
    if(k>=num.length())return "0";
    for(int i=0;i<num.length();i++){
        while(!st.empty() && st.top()>num[i] && k!=0){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }    
    string num2="";
    while(!st.empty()){
        num2=st.top()+num2;
        st.pop();
    }
    while(k>0){
        num2.pop_back();
        k--;
    }   
    int zeroCnt=0;
    for(int i=0;i<num2.length();i++){
        if(num2[i]=='0')zeroCnt++;
        else break;
    }
    num2=num2.substr(zeroCnt);
    return (num2=="" || num2=="\0")?"0":num2;
}
};
int main()
{

    return 0;
}