// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    if(mat.empty())return false;
    if(mat==target)return true;
    vector<vector<int>>a=mat;
    // 1st rotation
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            a[j][mat[0].size()-i-1]=mat[i][j];
        }
    }
    if(a==target)return true;
    mat=a;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            a[j][mat[0].size()-i-1]=mat[i][j];
        }
    }
    if(a==target)return true;
    mat=a;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            a[j][mat[0].size()-i-1]=mat[i][j];
        }
    }
    if(a==target)return true;
    return false;
}
};
int main()
{

    return 0;
}