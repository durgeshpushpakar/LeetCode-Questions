// https://leetcode.com/problems/domino-and-tromino-tiling/
// explanation-
// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/1620975/C%2B%2BPython-Simple-Solution-w-Images-and-Explanation-or-Optimization-from-Brute-Force-to-DP
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
const int mod=1e9+7;
int helper(int i, int n, bool previousGap){
    if(i>n)return 0;
    if(i==n){
        if(previousGap)return 0;
        return 1;
    }
    if(previousGap==false){
        int a=helper(i+1, n, false);
        int b=helper(i+2, n, false);
        int c=helper(i+2, n, true);
        return a+b+(2l*c)%mod;
    }
    else{
        int a=helper(i+1, n, false);
        int b=helper(i+1, n, true);
        return (a+b)%mod;
    }
}
int numTilings(int n) {
    return helper(0, n, false);
}
};
int main()
{
    Solution s;
    cout<<s.numTilings(4);
    return 0;
}