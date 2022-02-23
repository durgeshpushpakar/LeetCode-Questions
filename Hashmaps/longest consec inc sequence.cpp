#include<bits/stdc++.h>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    int ansLen = 1;
    int ansStart=arr[0];
    unordered_map<int, bool>map;
    unordered_map<int, int>index;
    for(int i=0;i<n;i++){
        map[arr[i]]=false;
        index[arr[i]]=i;
    }
    for(int i=0;i<n;i++){
        int start=arr[i];
        if(map[start])continue;
        map[start]=true;
        int k=arr[i]+1;
        int len=1;
        while(1){
            if(map.count(k) && !map[k]){
                map[k]=true;
                len++;
                k++;
            }
            else break;
        }
        int j=arr[i]-1;
        while(1){
            if(map.count(j) && !map[j]){
                map[j]=true;
                start=j;
                len++;
                j--;
            }
            else break;
        }
        if(len==ansLen && index[ansStart]>index[start]){
            ansLen=len;
            ansStart=start;
        }
        else if(len>ansLen){
            ansLen=len;
            ansStart=start;
        }
    }
    return {ansStart, ansStart+ansLen-1};
}
int main()
{

    return 0;
}