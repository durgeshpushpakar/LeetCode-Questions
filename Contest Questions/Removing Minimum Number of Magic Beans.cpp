#include<bits/stdc++.h>
using namespace std;
/*FAILED*/
class Solution {
public:
long long minimumRemoval(vector<int>& beans) {
    long long ans=LLONG_MAX;
    int maximum=INT_MIN;
    int n=beans.size();
    for(int i=0;i<n;i++){
        maximum=max(maximum, beans[i]);
    }    
    for(int k=1;k<=maximum;k++){
        long long smallAns=0;
        for(int i=0;i<n;i++){
            if(beans[i]<k){
                smallAns+=beans[i];
            }
            else smallAns+=beans[i]-k;
            if(smallAns>ans)break;
        }
        ans=min(ans, smallAns);
    }
    return ans;
}
};
int main()
{

    return 0;
}