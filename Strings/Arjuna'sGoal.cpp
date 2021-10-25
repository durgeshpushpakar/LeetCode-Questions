#include<bits/stdc++.h>
using namespace std;
int minimumNoOfShoots(int H[], int n){
    unordered_map<int, queue<int>>indexes;
    int ans=0;
    for(int i=0;i<n;i++){
        indexes[H[i]].push(i);
    }
    for(int i=0;i<n;i++){
        if(H[i]==-1)continue;
        int temp=H[i]-1;
        while(temp>=1){
            if(indexes[temp].front()>i){
                H[indexes[temp].front()]=-1;
                indexes[temp].pop();
                temp--;
            }
            else break;
        }
        if(indexes[H[i]].front()==i)indexes[H[i]].pop();
        ans++;
    }
    return ans;
}
int main()
{   
    // int H[5]={5,4,3,2,1};
    int H[7]={2,3,1,2,2,4,4};
    cout<<minimumNoOfShoots(H, 7);
    return 0;
}