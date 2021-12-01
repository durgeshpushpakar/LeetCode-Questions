#include<bits/stdc++.h>
using namespace std;
vector<int>* getPathBFS(bool **edges, int n, int sv, int v2 ){
    vector<int>*ans=new vector<int>();
    queue<int>q;
    unordered_map<int, int>parent;
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)visited[i]=false;
    q.push(sv);
    parent.insert(make_pair(sv, -1));
    visited[sv]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(edges[front][i] && !visited[i]){
                if(i==v2){
                    int temp=v2;
                    ans->push_back(temp);
                    while(temp!=sv){
                        temp=parent[temp];
                        ans->push_back(temp);
                    }
                    break;
                }
                q.push(i);
                parent.insert(make_pair(i, sv));
                visited[i]=true;
            }
        }
    }
    delete [] visited;
    return ans;
}
int main()
{
    int v, e;
    cin >> v >> e;
    bool **graph = new bool *[v];
    for (int i = 0; i < v; ++i)
    {
        graph[i] = new bool[v]();
    }
    for (int i = 0, a, b; i < e; ++i)
    {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    int start, end;
    cin >> start >> end;
    vector<int> *output = getPathBFS(graph, v, start, end);
    if (output != NULL)
    {
        for (int i = 0; i < output->size(); ++i)
        {
            cout << output->at(i) << " ";
        }
        delete output;
    }
    for (int i = 0; i < v; ++i)
    {
        delete[] graph[i];
    }
    delete[] graph;
}