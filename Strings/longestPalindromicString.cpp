#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string longestPalindrome(string s) {
    string largestPalin=""+s[0];
    for(int i=0;i<=s.length();i++){
        for(int j=0;j<s.length();j++){
            string temp=s.substr(j, i);
            if(j>=1 && j<s.length()){
                
            }
        }
    }

}
};
int main()
{

    return 0;
}