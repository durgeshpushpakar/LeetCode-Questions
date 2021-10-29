// https://leetcode.com/problems/partition-labels/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> partitionLabels(string s) {
    vector<int>ans;
    unordered_map<char, int>lastIndex;
    for(int i=0;i<s.length();i++)lastIndex[s[i]]=i;
    int i=0;
    while(i<s.length()){
        int end=lastIndex[s[i]];
        int j=i+1;
        while(j<=end){
            end=max(end, lastIndex[s[j++]]);
        }
        ans.push_back(end-i+1);
        i=end+1;
    }
    return ans;
}
};
int main()
{

    return 0;
}