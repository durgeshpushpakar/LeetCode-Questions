#include<bits/stdc++.h>
using namespace std;
/*
Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
*/
class Pair{
    public:
    int freq;
    char c;
    Pair(int f, char x){
        freq=f;
        c=x;
    }
};
class Solution {
public:

string repeatLimitedString(string s, int limit) {
    queue<Pair>q;
    vector<int>counts(26, 0);
    string ans;
    for(int i=0;i<s.length();i++){
        counts[s[i]-'a']++;
    }
    for(int i=25;i>=0;i--){
        if(counts[i]==0)continue;
        if(q.empty()){
            int t=limit;
            if(counts[i]>=t){
                while(t--){
                    s.push_back((char)i+'a');
                    counts[i]--;
                }
            }
            else {
                while(counts[i]--)s.push_back((char)i+'a');
            }
            if(counts[i]>0){
                Pair temp(counts[i], (char)i+'a');
                q.push(temp);
            }
        }
        if(q.front().freq>0){
            
        }
    }
}
};