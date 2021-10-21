// https://leetcode.com/problems/merge-intervals/
#include<bits/stdc++.h>
using namespace std;
bool comparator(const vector<int>&v1, vector<int>&v2){
    return v1[1]>v2[1];
}
vector<vector<int>> merge(vector<vector<int>>& arr) {
    vector<vector<int>>ans;
    if(arr.size()==0)return ans;
    sort(arr.begin(), arr.end());
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        int size=ans.size();
        if(ans[size-1][1]>=arr[i][0]){
            if(ans[size-1][1]>=arr[i][1])continue;
            ans[size-1][1]=arr[i][1];
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>>arr {{3, 5, 1},
                            {4, 8, 6},
                            {7, 2, 9}};
    sort(arr.begin(), arr.end(), comparator);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}