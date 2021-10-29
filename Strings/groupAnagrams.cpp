// https://leetcode.com/problems/group-anagrams/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>>map;
    for(int i=0;i<strs.size();i++){
        string s=strs[i];
        sort(s.begin(), s.end());
        map[s].push_back(strs[i]);
    }
    vector<vector<string>>ans;
    for(auto itr=map.begin();itr!=map.end();itr++){
        ans.push_back(itr->second);
    }
    return ans;
}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}