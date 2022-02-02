#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> findAnagrams(string s, string p) {
    vector<int>ans;
    int pLen=p.length();
    int sLen=s.length();
    if(sLen<pLen)return ans;
    vector<int>freqP(257, 0);
    vector<int>freqS(257, 0);

    for(int i=0;i<p.length();i++)(freqP[p[i]])++;  

    int i=0, j=pLen-1;
    for(int k=i;k<=j;k++)freqS[s[k]]++;

    while(i<=sLen-pLen){
        if(freqP==freqS)ans.push_back(i);
        freqS[s[i++]]--;
        freqS[s[++j]]++;
    }
    if(freqP==freqS)ans.push_back(i-1);
    return ans;
}
};
int main()
{

    return 0;
}