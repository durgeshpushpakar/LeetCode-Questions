#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
bool isAnagram(string s, string t) {
    vector<int>freq1(26,0);
    vector<int>freq2(26,0);
    for(int i=0;i<s.length();i++){
        freq1[s[i]-'a']++;
    }
    for(int i=0;i<t.length();i++){
        freq2[t[i]-'a']++;
    }
    return freq1==freq2;        
}
int strStr(string haystack, string needle) {
    if(needle=="")return 0;
    int k=needle.length();
    for(int i=0;i<=haystack.length()-k;i++){
        string subst=haystack.substr(i,k);
        if(needle==subst)return i;
    }
    return -1;
}
int main(){

    return 0;
}