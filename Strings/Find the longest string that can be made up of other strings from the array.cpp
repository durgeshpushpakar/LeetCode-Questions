#include<bits/stdc++.h>
using namespace std;
bool comp(string &a, string &b){
    return a.length()>b.length();
}
bool helper(unordered_map<string, bool>&map, string &s, bool orignal){
    if(s.length()==0)return true;
    for(int i=0;i<s.length();i++){
        if(i==s.length()-1 && orignal)continue;
        string left=s.substr(0, i+1);
        string right=s.substr(i+1);
        if(map.find(left)!=map.end() && map[left]){
            return helper(map, right, 0);
        }
    }
    return false;
}
string solve(vector<string>&arr){
    int n=arr.size();
    unordered_map<string, bool>map;
    for(string &x:arr)map[x]=1;
    sort(arr.begin(), arr.end(), comp);
    for(int i=0;i<n;i++){
        if(helper(map, arr[i], 1))return arr[i];
    }
    return "-1";
}
int main()
{
    vector<string> listofwords = { "geeks", "for", "geeksfor"};
    cout << solve(listofwords);
 
    return 0;
}
