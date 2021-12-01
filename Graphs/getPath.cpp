#include<bits/stdc++.h>
using namespace std;
void getPath(int **edges, int n, int sv, bool *visited, vector<int> &path, int v2){
    path.push_back(sv);
    visited[sv]=true;
    if(sv==v2){
        for(int i=path.size()-1;i>=0;i--)cout<<path[i]<<" ";
        return;
    }     
    for(int i=0;i<n;i++){
        if(i==sv)continue;
        if(edges[sv][i]==1 && !visited[i]){
            getPath(edges, n, i, visited, path, v2);
        }
    }
}   
void solve(){
    int n;
    int e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i]=new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }
    for(int i=0; i<e; i++){
        int f,s;
        cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int v1, v2;cin>>v1>>v2;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    vector<int>path;
    getPath(edges, n, v1, visited, path, v2);
    delete [] visited;
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}
int main()
{
    solve();
    return 0;
}