#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool comparator(vector<int>&arr1, vector<int>&arr2){
    return arr1[0]<arr2[0];
}
vector<int> findRightInterval(vector<vector<int>>& arr) {
    unordered_map<int, int>idx;// map from start index to its index in the arr
    for(int i=0;i<arr.size();i++){
        idx[arr[i][0]]=i;
    }
    vector<vector<int>>arr2=arr;
    sort(arr2.begin(), arr2.end(), comparator);
    
}
};
int main()
{

    return 0;
}