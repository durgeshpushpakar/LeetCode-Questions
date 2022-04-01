#include<bits/stdc++.h>
using namespace std;
vector<int>*BFS(vector<vector<int>>&edges, int start, int end){
    int n=edges.size();
    vector<bool> visited(n, false);
    vector<int>*ans=new vector<int>;
    if(start==end){
        ans->push_back(start);
        return ans;
    }
    unordered_map<int, int>parent;
    parent[start]=-1;
    visited[start]=true;
    // memset(visited, false, sizeof visited);
    
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int front=q.front();
            q.pop();
            for(int i=0;i<n;i++){
                if(!visited[i] && edges[front][i]){
                    parent[i]=front;
                    visited[i]=true;
                    q.push(i);
                    if(i==end){
                       int temp=end;
                       while(temp!=-1){
                           ans->push_back(temp);
                           temp=parent[temp];
                       }
                       return ans;
                    }                    
                }
            }
        }
    }
    return NULL;
}















/*
void BFS(vector<vector<int>>&edges, int start, int end){
    int n=edges.size();
    queue<int>q;

    unordered_map<int, int>parent;
    parent[start]=-1;

    vector<bool>visited(n, false);
    visited[start]=true;

    if(start==end){
        cout<<start;
        return;
    }

    q.push(start);
    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[i][vertex]){
                if(i==end){
                    cout<<i<<" ";
                    int temp=vertex;
                    while(temp!=-1){
                        cout<<temp<<" ";
                        temp=parent[temp];
                    }
                    return;
                }
                q.push(i);
                visited[i]=true;
                parent[i]=vertex;
            }
        }
    }
}
*/
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
    if(start>=n || end>=n)return 0;
    BFS(edges, start, end);
    return 0;
}