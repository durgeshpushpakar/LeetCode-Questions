// https://leetcode.com/problems/longest-palindrome/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int longestPalindrome(string s) {
    unordered_map<int, int>freq;
    for(int i=0;i<s.length();i++)freq[int(s[i])]++;
    int maxLength=0;
    int maxOddLength=INT_MIN;
    for(auto itr=freq.begin();itr!=freq.end();itr++){
        if(itr->second%2==1){
            if(itr->second>maxOddLength)maxOddLength=itr->second;
            maxLength+=itr->second-1;
        }
        else if(itr->second%2==0){
            maxLength+=itr->second;
        }
    }      
    if(maxOddLength!=INT_MIN){
        maxLength++;
    }     
    return maxLength;
}
};
int main()
{
    cout<<(int)'A';
    return 0;
}