#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
    if(s.length()!=t.length())return false;
    vector<int>umap1(26, 0);
    vector<int>umap2(26, 0);
    for(int i=0;i<s.length();i++)umap1[s[i]-'a']++;
    for(int i=0;i<t.length();i++)umap2[t[i]-'a']++;
    return umap1==umap2;
}
int main()
{

    return 0;
}