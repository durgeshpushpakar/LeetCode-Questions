#include<bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0;i<9;i++){  //cols
        unordered_map<char, int>temp;
        for(int j=0;j<9;j++){ //row
            temp[board[j][i]]++;
            if(temp[board[j][i]]>1 && board[j][i]!='.')return false;
        }
    }
    for(int i=0;i<9;i++){  //rows
        unordered_map<char, int>temp;
        for(int j=0;j<9;j++){ //col
            temp[board[i][j]]++;
            if(temp[board[i][j]]>1 && board[i][j]!='.')return false;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            unordered_map<char, int>temp;
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    temp[board[k+(3*i)][l+(3*j)]]++;
                    if(temp[board[k+(3*i)][l+(3*j)]]>1 && board[k+(3*i)][l+(3*j)]!='.')return false;
                }
            }
        }
    }
    return true;        
}

int main()
{

    return 0;
}