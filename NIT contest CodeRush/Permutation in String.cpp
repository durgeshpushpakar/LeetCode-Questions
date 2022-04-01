#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// to check if s2 contains a permutation of s1
bool checkInclusion(string s1, string s2) {
    int n1=s1.length();    
    int n2=s2.length();  
    if(n1==0)return false;
    if(n2<n1)return false;  
    vector<int>s1Map(257, 0);
    vector<int>s2Map(257, 0);
    for(int i=0;i<n1;i++){
        s1Map[s1[i]]++;
    }
    int i=0;
    int j=i;
    for(;j<n1;j++){
        s2Map[s2[j]]++;
    }
    
    if(s1Map==s2Map)return true;
    while(j<n2 && i<j){
        s2Map[s2[j++]]++;
        s2Map[s2[i++]]--;
        if(s1Map==s2Map)return true;
    }

    return false;
}
};
int main()
{

    return 0;
}