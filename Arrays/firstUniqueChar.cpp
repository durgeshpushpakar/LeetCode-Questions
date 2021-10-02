#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
int firstUniqChar(string s) {
    vector<int>freq(26,0);
    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
    }
    for(int i=0;i<s.length();i++){
        if(freq[s[i]-'a'] ==1)return i;
    }
    return -1;

}
int main(){
    cout<<'c'-'a';
    return 0;
}