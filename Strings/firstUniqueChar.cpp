// https://leetcode.com/problems/first-unique-character-in-a-string/
#include<bits/stdc++.h>
using namespace std;
int firstUniqChar(string s) {
    unordered_map<char, int>umap;
    for(int i=0;i<s.length();i++)umap[s[i]]++;
    for(int i=0;i<s.length();i++)
        if(umap[s[i]]==1)return i;
    return -1;
}
// https://leetcode.com/problems/ransom-note/
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int>r;
    unordered_map<char, int>m;
    for(int i=0;i<ransomNote.length();i++)r[ransomNote[i]]++;
    for(int i=0;i<magazine.length();i++)m[magazine[i]]++;
    for(auto i=r.begin();i!=r.end();i++){
        if(i->second>m[i->first])return false;
    }
    return true;
}
int main()
{

    return 0;
}