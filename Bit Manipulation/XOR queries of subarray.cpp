// https://leetcode.com/problems/xor-queries-of-a-subarray/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){
    vector<int>prefix;
    int xorRes=0;
    for(int x:arr){
        xorRes= xorRes ^ x;
        prefix.push_back(xorRes);
    }    
    vector<int>ans;
    for(int i=0;i<queries.size();i++){
        int lower=queries[i][0];
        int upper=queries[i][1];
        if(lower==0){
            ans.push_back(prefix[upper]);
            continue;
        }
        ans.push_back(prefix[lower-1]^prefix[upper]);
    }
    return ans;
}
};
int main()
{

    return 0;
}