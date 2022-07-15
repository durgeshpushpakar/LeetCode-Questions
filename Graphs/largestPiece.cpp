#include<bits/stdc++.h>
using namespace std;
bool range(int i, int j, int n){
    return (i<n && j<n && i>=0 && j>=0);
}
int dfs(vector<vector<int>> &cake, int n, int i, int j, vector<vector<bool>>&visited){
    int dxdy[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
    visited[i][j]=true;
    int count=0;
    for(int k=0;k<4;k++){
        int newX=i+dxdy[k][0];
        int newY=j+dxdy[k][1];
        if(range(newX, newY, n) && !visited[newX][newY]){
            int smallCount=dfs(cake, n, newX, newY, visited);
            count+=smallCount;
        }
    }
    return count+1;
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    vector<vector<bool>>visited(n, vector<bool>(n, false));
    int largestCount=0;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j]==1 && !visited[i][j]){
                largestCount=max(dfs(cake, n, i, j, visited), largestCount);
            }
        }
    }
    return largestCount;
}
#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &cake, vector<vector<bool>> &visited, int x, int y, int n)
{
	if (visited[x][y])
	{
		return 0;
	}
	visited[x][y] = true;
	int count = 1;
	int dx[] = {0, 0, -1, 1}; // Change in x while taking four moves
	int dy[] = {1, -1, 0, 0}; // Change in y while taking four moves
	for (int i = 0; i < 4; ++i)
	{
		int X = x + dx[i];
		int Y = y + dy[i];
		if (X >= 0 && X < n && Y >= 0 && Y < n && cake[X][Y] == 1)
		{
			count += dfs(cake, visited, X, Y, n);
		}
	}
	return count;
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
	int biggestPieceSize = 0;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cake[i][j] == 1 && !visited[i][j])
			{
				biggestPieceSize = max(biggestPieceSize, dfs(cake, visited, i, j, n));
			}
		}
	}
	return biggestPieceSize;
}