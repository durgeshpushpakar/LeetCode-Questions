#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<string> summaryRanges(vector<int>& arr) {
    int n=arr.size();
    vector<string>ans;
    for(int i=0;i<n;i++){
        int j=i;
        while (j+1 < n && arr[j] + 1 == arr[j + 1]){
            j++;
        }
        if(i==j){
            string c="";
            c+=to_string(arr[i]);
            ans.push_back(c);
        }
        else{
            string s="";
            s += to_string(arr[i]);
            s += "->";
            s += to_string(arr[j]);
            ans.push_back(s);
        }
        i=j;
    }
    return ans;
}
};