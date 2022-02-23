#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
long long coutPairs(vector<int>& arr, int k) {
    long long ans=0;
    int n=arr.size();
    int divi=0;
    int rem=0;
    for(int i=0;i<n;i++){
        if(arr[i]%k==0){
            divi++;
        }
    }
    rem=n-divi;
    long long pairCnt, pairCntDivi;
    if(divi==0)return 0;
    pairCntDivi=divi*(divi-1)/2;
    pairCnt=divi*rem;
    return pairCnt+pairCntDivi;
}
};