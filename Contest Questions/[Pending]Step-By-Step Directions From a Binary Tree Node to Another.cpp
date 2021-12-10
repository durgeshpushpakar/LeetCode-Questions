// https://leetcode.com/contest/weekly-contest-270/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Pair{
    public:
    string path;
    char found;
    bool isFound;
    Pair(){
        path="";
        found='\0';
        isFound=false;
    }
    
    Pair(string p, char f, bool i){
        path=p;
        found=f;
        isFound=i;
    }
};
class Solution {
public:
    Pair helper(TreeNode* root, int s, int d){
        if(root->left==NULL && root->right==NULL){
            return Pair();
        }
        if(root->left->val==s){

            return Pair()
        }
        Pair leftAns=helper(root->left, s, d);
        Pair rightAns=helper(root->right, s, d);
        if(leftAns.isFound)
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        return helper(root, startValue, destValue).path;
    }
};
int main()
{

    return 0;
}