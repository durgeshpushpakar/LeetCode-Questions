// https://leetcode.com/problems/reshape-the-matrix/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int r1=mat.size();
    int c1=mat[0].size();
    int len=r1*c1;
    vector<vector<int>>ans;
    if(r*c!=len){
        ans=mat;
        return ans;
    }       
    int i=0, j=0;
    int k=0;
    vector<int>temp;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            temp.push_back(mat[i][j]);
            k++;
            if(k==c){
                ans.push_back(temp);
                temp.erase(temp.begin(), temp.end());
                k=0;
            }
        }
    }
    return ans;
}
int main(){
    return 0;
}