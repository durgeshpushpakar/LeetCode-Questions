// https://leetcode.com/problems/multiply-strings/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string add(string s, string t){
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int i=0, carry=0;
    string ans="";
    while(i<s.length() && i<t.length()){
        int temp=carry+(s[i]-'0')+(t[i]-'0');
        carry=temp/10;
        ans.push_back((char)((temp%10)+'0'));
        i++;
    }
    while(i<s.length()){
        int temp=carry+s[i]-'0';
        carry=temp/10;
        ans.push_back((char)((temp%10)+'0'));
        i++;
    }
    while(i<t.length()){
        int temp=carry+t[i]-'0';
        carry=temp/10;
        ans.push_back((char)((temp%10)+'0'));
        i++;
    }
    if(carry!=0)ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());
    return ans;
}
string multiply(string num1, string num2) {
    string temp1=(num1.length()>=num2.length())?num1:num2;
    if(num1=="0" || num2=="0")return "0";
    string sum="0";
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int i=0, carry=0;
    while(i<num2.length()){
        int j=0;
        string ans="";
        int carry=0;
        while(j<num1.length()){
            int temp = carry + (num1[j] - '0') * (num2[i] - '0');
            carry=temp/10;
            ans.push_back((temp%10)+'0');
            j++;
        }
        if(carry!=0)ans.push_back(carry+'0');
        reverse(ans.begin(), ans.end());
        ans.insert(ans.end(), i, '0');
        sum=add(ans, sum);
        i++;
    }
    return sum;
}
};
int main()
{
    Solution sol;
    cout<<sol.multiply("123999994524185", "99999992333444498989898444444")<<endl;
    // cout<<(char)('0'+4)<<endl;
    // cout<<'4'-'0';
    return 0;
}