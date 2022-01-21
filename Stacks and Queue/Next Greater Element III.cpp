#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int nextGreaterElement(int N) {
    string s=to_string(N);
    int n=s.length();
    for(int i=n-2;i>=0;i--){
        if(s[i]>=s[i+1])continue;
        else if(s[i]<s[i+1]){
            auto uBound=upper_bound(s.begin()+i+1, s.end(), s[i]);
            iter_swap(uBound, s.begin()+i);
            sort(s.begin()+i+1, s.end());
        }
    }
    if(atoi(s.c_str())==N)return -1;
    return atoi(s.c_str());
}
};
int main()
{

    return 0;
}