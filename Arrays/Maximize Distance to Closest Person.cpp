#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int maxDistToClosest(vector<int>& seats) {
    int left=-1;
    int ans=0;
    for(int i=0;i<seats.size();i++){
        if(seats[i]==1){
            if(left==-1){
                ans=max(ans, i-0);
            }
            else ans=max(ans, (i-left)/2);
            left=i;
        }
        else if(seats[i]==0 && i==seats.size()-1){
            ans=max(ans, i-left);
        }
    }
    cout<<"left="<<left<<endl;
    return ans;
}
};
int main()
{
    Solution s;
    vector<int>arr{1,0,0,0};
    cout<<s.maxDistToClosest(arr);
    return 0;
}