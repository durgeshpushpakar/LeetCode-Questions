#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &edges, int start, int end, vector<bool> &visited, vector<int> &path)
{
    if (start == end)
    {
        path.push_back(end);
        for (auto it = path.rbegin(); it != path.rend(); it++)
            cout << *it << " ";
    }
    int n = edges.size();
    visited[start] = true;
    path.push_back(start);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && edges[i][start])
        {
            DFS(edges, i, end, visited, path);
        }
    }
    path.pop_back();
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    int start, end;
    cin >> start >> end;
    vector<int> path;
    DFS(edges, start, end, visited, path);
    return 0;
}