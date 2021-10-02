#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string ans="";
    if(strs.size()==0)return ""; 
    string temp=strs[0];
    for(int i=0;i<temp.length();i++){
        for(int j=1;j<strs.size();j++){
            if(strs[j][i]!=temp[i])return ans;
        }
        ans+=temp[i];
    }
    return ans;   
}
int main(){

    return 0;
}