#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int r, c, nc;
bool range(int i, int j, int m, int n){
    return (i>=0 && i<m && j>=0 && j<n);
}
void BFS(vector<vector<int>>&arr){
    int m=arr.size(), n=arr[0].size();
    queue<pair<int, int>>q;
    int color = arr[r][c];
    arr[r][c]=nc;
    q.push({r, c});
    int dxdy[4][2] = {{0,1},{1,0}, {-1,0}, {0,-1}};
    while(!q.empty()){
        pair<int, int> front= q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int newR=front.first+dxdy[i][0];
            int newC=front.second+dxdy[i][1];
            if(range(newR, newC, m, n) && arr[newR][newC]==color){
                arr[newR][newC]=nc;
                q.push({newR, newC});
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<vector<int>>ans(image.begin(), image.end());
    r=sr;
    c=sc;
    nc=newColor;
    if(ans[r][c]==nc)return ans;
    BFS(ans);
    return ans;    
}
};
int main()
{
    
    return 0;
}