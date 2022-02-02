// https://leetcode.com/problems/detect-capital/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool capital(char s){
    return (s>='A' && s<='Z');
}    
bool detectCapitalUse(string word) {
    int n=word.length();
    if(n==0 || n==1)return true;
    char firstLetter = word[0];
    char secondLetter= word[1];
    if(capital(firstLetter)){
        if(capital(secondLetter)){
            for(int i=2;i<n;i++){
                if(!capital(word[i]))return false;
                else continue;
            }
            return true;
        }
        else{
            for (int i = 2; i < n; i++)
            {
                if (capital(word[i]))
                    return false;
                else
                    continue;
            }
            return true;
        }
    }
    else {
        if(capital(secondLetter))return false;
        else{
            for (int i = 2; i < n; i++)
            {
                if (capital(word[i]))
                    return false;
                else
                    continue;
            }
            return true;
        }
    }
    
}
};
int main()
{
    string s="USA";
    Solution S;
    cout<<S.detectCapitalUse(s);
    // cout<<S.capital(s[0]);
    return 0;
}