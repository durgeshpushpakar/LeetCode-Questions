#include<bits/stdc++.h>
using namespace std;
// 1 3 3 1
// 1 4 6 4 1
// 0 1 2   1 1
vector<int> getRow(int rowIndex) {
    if(rowIndex==0){
        vector<int>ans{1};
        return ans;
    }
    else if(rowIndex==1){
        vector<int>ans{1,1};
        return ans;
    }
    vector<int>smallAns=getRow(rowIndex-1);
    vector<int>ans{1};
    int j=1;
    for(int i=0;i<smallAns.size()-1;i++){
        ans.push_back(smallAns[i]+smallAns[i+1]);
    }
    ans.push_back(1);
    return ans;
}
int main()
{

    return 0;
}