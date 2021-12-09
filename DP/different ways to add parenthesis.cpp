//Question- https://leetcode.com/problems/different-ways-to-add-parentheses/
// Nice Solution(DP)- https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/66331/C%2B%2B-4ms-Recursive-and-DP-solution-with-brief-explanation
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int stoi(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans=(10*ans)+(s[i]-'0');
    }
    return ans;
}
bool isOperator(char x){
    return (x=='+' || x=='-' || x=='*');
}
int eval(int x, int y, char op){
    if(op=='-')return x-y;
    else if(op=='+')return x+y;
    else if(op=='*')return x*y;
    return INT_MAX;
}
vector<int> diffWaysToCompute(string s) {
    // base case 
    vector<int>ans;
    if(s.length()<=0)return ans;
    // if(s.length()<=5){
    //     int num=0;
    //     for(int i=0;i<s.length();i++){
    //         if(isOperator(s[i]))num++;
    //     }
    //     if(num==0){
    //         return {stoi(s)};
    //     }
    //     else if(num==1){
    //         for(int i=0;i<s.length();i++){
    //             if(isOperator(s[i]))
    //                 return {eval(stoi(s.substr(0, i-1)), stoi(s.substr(i+1)), s[i])};
    //         }
    //     }
    // }
    for(int i=0;i<s.length();i++){
        if(isOperator(s[i])){
            vector<int>subAns1=diffWaysToCompute(s.substr(0, i));
            vector<int>subAns2=diffWaysToCompute(s.substr(i+1));
            for(auto itr:subAns1){
                for(auto itr2:subAns2){
                    ans.push_back(eval(itr, itr2, s[i]));
                }
            }
        }
    }
    if(ans.empty())return {stoi(s)};
    return ans;
}
};
