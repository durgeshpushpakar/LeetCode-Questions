#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> partitionLabels(string s) {
    int n=s.length();
    unordered_map<char, int>lastIdx;
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        if(!lastIdx.count(s[i]))lastIdx[s[i]]=i;
    }   
    int i=0; 
    while(i<n){
        int start = i;
        int lastIndex = lastIdx[s[i]];
        while (i <= lastIndex){
            lastIndex=max(lastIndex, lastIdx[s[i]]);
            i++;
        }
        ans.push_back(lastIndex - start + 1);
    }
    return ans;
}
};
int main()
{
    
    return 0;
}