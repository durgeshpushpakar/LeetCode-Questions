// https://leetcode.com/problems/pascals-triangle/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int n) {
    vector<vector<int>>ans;
    if(n==0)return ans;
    if(n==1){
        vector<int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        return ans;
    }
    if(n==2){
        vector<int>x;
        x.push_back(1);
        ans.push_back(x);
        vector<int>temp;
        temp.push_back(1);
        temp.push_back(1);
        ans.push_back(temp);
        return ans;
    }
    vector<vector<int>>smallAns=generate(n-1);
    int len=smallAns.size();
    vector<int>temp=smallAns[len-1];
    vector<int>newRow;
    for(int i=0;i<temp.size()+1;i++){
        if(i==0 || i==temp.size()){
            newRow.push_back(1);
            continue;
        }
        int x=temp[i-1]+temp[i];
        newRow.push_back(x);
    }
    smallAns.push_back(newRow);
    return smallAns;
}