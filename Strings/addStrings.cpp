// https://leetcode.com/problems/add-strings/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int I(char c){return c-'0';}
string addStrings(string num1, string num2) {
    int carry=0;
    int i=num1.length()-1;
    int j=num2.length()-1;
    string ans="";
    while(i>=0 && j>=0){
        int temp=I(num1[i])+I(num2[j])+carry;
        carry=temp/10;
        int digit=temp%10;
        ans.push_back(to_string(digit)[0]);
        i--;j--;
    }
    while(i>=0){
        int temp=I(num1[i])+carry;
        carry=temp/10;
        int digit=temp%10;
        ans.push_back(to_string(digit)[0]);
        i--;
    }
    while(j>=0){
        int temp=I(num2[j])+carry;
        carry=temp/10;
        int digit=temp%10;
        ans.push_back(to_string(digit)[0]);
        j--;
    }
    if(carry!=0)ans.push_back(to_string(carry)[0]);
    reverse(ans.begin(), ans.end());
    return ans;
}
};
int main()
{

    return 0;
}