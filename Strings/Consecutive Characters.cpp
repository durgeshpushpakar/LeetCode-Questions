#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int maxPower(string s) {
    int ans=1;
    int i=0;
    while(i<s.length()){
        int count=1;
        if(i==s.length()-1)break;
        while(s[i+1]==s[i]){
            count++;
            i++;
        }
        ans=max(count, ans);
        i++;
    }    
    return ans;
}
};
int main()
{

    return 0;
}