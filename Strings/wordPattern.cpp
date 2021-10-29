#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool wordPattern(string pattern, string s) {
    stringstream ss(s);
    string word;
    unordered_map<string, char>umap;
    unordered_set<char>umap2;
    int wordCount=0;
    while(!ss.eof() && wordCount<pattern.length()){
        ss>>word;
        if(umap.count(word)==1 && umap[word]!=pattern[wordCount]){
            return false;
        }
        else if(umap2.count(pattern[wordCount])==1 && umap.count(word)==0)return false;
        umap.insert(make_pair(word, pattern[wordCount]));
        umap2.insert(pattern[wordCount]);
        wordCount++;
    }
    if(wordCount!=pattern.length() || !ss.eof())return false;
    return true;
}

};
int main()
{
    Solution S;
    string pattern="abba";
    string s="dog cat cat fish";
    if(S.wordPattern(pattern, s))cout<<true;
    else cout<<false;
    return 0;
}