#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int compareVersion(string s, string t) {
    int i=0, j=0;
    int len1=s.length();
    int len2=t.length();
    while(i<len1 || j<len2){
        int num1=0, num2=0;
        while(i<len1 && s[i]!='.'){
            num1 = (num1*10)+(s[i]-'0');
            i++;
        }
        while(j<len2 && t[j]!='.'){
            num2 = (num2*10)+(t[j]-'0');
            j++;
        }
        if(num1<num2)return -1;
        else if(num1>num2)return 1;
        i++;j++;
    }
    return 0;
}
};
int main()
{
    Solution S;
    string s="1";
    string t="1.0.1";
    cout<<S.compareVersion(s, t);
    return 0;
}