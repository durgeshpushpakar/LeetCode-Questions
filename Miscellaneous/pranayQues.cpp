#include<bits/stdc++.h>
using namespace std;
void helper(string r, string b, string k, string &ans){
    if(r=="" && b==""){
        if(k<ans)ans=k;
        return;
    }
    if(!r.empty()){
        b.push_back(r[0]);
        r=r.substr(1);
        helper(r, b, k, ans);
        r.insert(r.begin(), b.back());
        b.pop_back();
    }
    if(!b.empty()){
        k.push_back(b.back());
        b.pop_back();
        helper(r, b, k, ans);
    }
}
string solve(int n, string s){
    string b="", k="", ans="~~";
    helper(s, b, k, ans);
    return ans;
}
int main()
{
    cout<<solve(3, "bac");
    return 0;
}