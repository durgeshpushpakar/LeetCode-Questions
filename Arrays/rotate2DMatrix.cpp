#include<bits/stdc++.h>
using namespace std;
void transpose(vector<vector<int>>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<=i;j++)
            swap(arr[i][j], arr[j][i]);
    }
}
void reverseRow(vector<vector<int>>&arr){
    for(int i=0;i<arr.size();i++){
        reverse(arr[i].begin(), arr[i].end());
    }
}
void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    reverseRow(matrix);
}
int main()
{

    return 0;
}