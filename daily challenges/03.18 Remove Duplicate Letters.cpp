#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string removeDuplicateLetters(string s) {
    vector<int>freq(26, 0);
    vector<bool>vis(26, false);
    stack<char>st;
    for(char x:s){
        freq[x-'a']++;
    }    
    for(char x:s){
        freq[x-'a']--;
        if(vis[x-'a'])continue;
        while(!st.empty() && x<st.top() && freq[st.top()-'a']>0){
            vis[st.top()-'a']=false;
            st.pop();
        }
        st.push(x);
        vis[x-'a']=true;
    }
    string ans="";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
};