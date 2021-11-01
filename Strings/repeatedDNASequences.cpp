// https://leetcode.com/problems/repeated-dna-sequences/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
    vector<string>ans;
    if(s.length()<10)return ans; 
    unordered_map<string, int>umap;
    for(int i=0;i<=s.length()-10;i++)umap[s.substr(i, 10)]++;
    for(auto itr=umap.begin();itr!=umap.end();itr++)if(itr->second>1)ans.push_back(itr->first);
    return ans;
}
};
int main()
{

    return 0;
}