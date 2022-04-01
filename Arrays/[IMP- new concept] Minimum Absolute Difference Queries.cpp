#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> minDifference(vector<int>& arr, vector<vector<int>>& queries) {
    int prefix[100001][101] = {}, cnt[101] = {};
    // vector<vector<int>>prefix(100001, vector<int>(101, 0));
    // vector<int>cnt(101, 0);
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        cnt[arr[i]]++;
        for(int j=1;j<101;j++){
            prefix[i+1][j]=cnt[j];
        }
    } 
    for(int j=0;j<queries.size();j++){
        int low=queries[j][0], high=queries[j][1];
        vector<int>temp(101, 0);
        for(int i=0;i<101;i++){
            temp[i]=prefix[high+1][i]-prefix[low][i];
        }
        int minDiff=INT_MAX, prev=-1;
        for(int i=1;i<101;i++){
            if(temp[i]!=0){
                if(prev==-1)prev=i;
                else {
                    minDiff=min(minDiff, i-prev);
                    prev=i;
                }
            }
        }
        ans.push_back((minDiff==INT_MAX) ? -1 : minDiff);
    }
    return ans;
}
};
int main()
{
    
    return 0;
}