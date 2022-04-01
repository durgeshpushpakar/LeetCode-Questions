// https://www.pramp.com/challenge/Y56aZmaj9Ptmd9wV9xvL
#include<vector>
#include<queue>
#include<iostream>


using namespace std;
class Pair{
    public:
  int x, y;
  Pair(int a, int b){
    x=a;
    y=b;
  }
};
bool range(int i, int j, int n, int m){
  return (i>=0 && i<n && j>=0 && j<m);
}
int BFS(const vector<vector<int>>&grid, int svi, int svj, int tr, int tc){
    int dxdy[4][2]={{1,0}, {0,-1}, {1,0}, {-1,0}};
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    int level=0;
    visited[svi][svj]=true;
    queue<Pair>q;
  Pair temp(svi, svj);
  q.push(temp);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Pair vertex=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newI=vertex.x + dxdy[i][0];            
                int newJ=vertex.y + dxdy[i][1];
                if(range(newI, newJ, n, m) && grid[newI][newJ]==1 && !visited[newI][newJ]){
                    if(newI==tr && newJ==tc)return level+1;
                    Pair temp1(newI, newJ);
                    q.push(temp1);
                    visited[newI][newJ]=true;   
                }
            }
        }
        
      level++;
    }
    return -1;
}
int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc)
{
    int n=grid.size();
    int m=grid[0].size();
    int ans = BFS(grid, sr, sc, tr, tc);
    return ans;
}
int main()
{
  return 0;
}
