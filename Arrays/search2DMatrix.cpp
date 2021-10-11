// https://leetcode.com/problems/search-a-2d-matrix/
// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
// both questions are same
#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r=matrix.size();
    int c=matrix[0].size();
    int i=0, j=c-1;
    while(i>=0 && i<r && j>=0){
        if(matrix[i][j]==target)return true;
        else if(matrix[i][j]>target)j--;
        else{
            i++;
        }
    }
    return false;

}
int main()
{

    return 0;
}