#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    string str;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin>>str;
    vector<pair<int, int>>arr;
    while(n--){
        int a, b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    // for A and D +++ //
    unordered_map<int, set<pair<int, int>>>d1;
    // for b and c ---  
    unordered_map<int, set<pair<int, int>>>d2;
    for(int i=0;i<arr.size();i++){
        pair<int, int>temp=arr[i];
        int keyD1 = temp.first + temp.second;
        int keyD2 = temp.first - temp.second;
        d1.
    }
    return 0;
}