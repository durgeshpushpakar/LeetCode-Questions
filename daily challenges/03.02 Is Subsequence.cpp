#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isSubsequence(string s, string t) {
    int sLen=s.length();
    int j=0;
    for(int i=0;i<sLen;i++){
        bool isFound=false;
        while(j<t.length()){
            if(s[i]==t[j]){
                j++;
                isFound=true;
                break;
            }
            j++;
        }
        if(!isFound)return false;
    }
    return true;    
}
};