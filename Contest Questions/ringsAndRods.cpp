#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int countPoints(string rings) {
    int n=rings.length();
    vector<unordered_set<int>>arr(10);
    int count=0;
    for(int i=0;i<n;i+=2){
        arr[rings[i+1]-'0'].insert(rings[i]);
    }
    for(int i=0;i<10;i++){
        if(arr[i].size()==3)count++;
    }
    return count;
}
};
int main()
{

    return 0;
}