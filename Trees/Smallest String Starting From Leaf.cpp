#include<bits/stdc++.h>
#include "TreeNode2.h"
using namespace std;
// returns true if s is smaller than t
bool compare(string s, string t){
    int i=0;// bae           be
    for(i=0;i<s.length() && i<t.length();i++){
        if(s[i]<t[i])return true;
        else if(t[i]<s[i])return false;
    }
    if(s.length()<t.length())return true;
    else return false;
}
class Solution {
public:
string ans;
Solution(){
    ans="~";
}
void helper(TreeNode *root, string s){
    char a=(char)root->val+'a';
    if(root->left==NULL && root->right==NULL){
        ans=min(ans, a+s);
    }
    helper(root->left, a+s);
    helper(root->right, a+s);
    
}
string smallestFromLeaf(TreeNode* root) {
    string s="";
    helper(root, s);
    return ans;
}
};
int main()
{
    string s="bae";
    string t="be";
    cout<<compare(s,t)?1:0;
    return 0;
}