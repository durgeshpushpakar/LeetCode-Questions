#include<bits/stdc++.h>
using namespace std;
bool comparator(const vector<int>&v1, vector<int>&v2){
    return v1[1]>v2[1];
}

int main()
{
    vector<vector<int>>arr {{3, 5, 1},
                            {4, 8, 6},
                            {7, 2, 9}};
    sort(arr.begin(), arr.end(), comparator);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    /*
    output
    4 8 6 
    3 5 1 
    7 2 9 
    */
    return 0;
}