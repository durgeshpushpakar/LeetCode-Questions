#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int u, v, w;
    Node(int a, int b, int c){
        u=a;v=b;w=c;
    }
};

bool comp(Node &a, Node &b){
    return (a.w<b.w);
}
// disjoint set function findParent
int findParent(vector<int>&parent, int node){
    if(parent[node]==node)return node;
    return parent[node]=findParent(parent, parent[node]);
}
// disjoint set function unionn
void unionn(vector<int> &parent, vector<int>&rank, int u, int v){
    u=findParent(parent, u);
    v=findParent(parent, v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

void Kruskal(vector<Node>&arr, int v){
    vector<int>parent(v), rank(v, 0);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    vector<Node>ans;
    for(Node x:arr){
        int p1=findParent(parent, x.u);
        int p2=findParent(parent, x.v);
        if(p1==p2)continue;
        ans.push_back(x);
        unionn(parent, rank, p1, p2);
    }
    for(Node x:ans){
        if(x.u<x.v)cout<<x.u<<" "<<x.v<<" "<<x.w;
        else cout<<x.v<<" "<<x.u<<" "<<x.w;
        cout<<endl;
    }
}
int main()
{
    int v, e;
    cin>>v>>e;
    vector<Node>arr;
    while(e--){
        int a, b, w;
        cin >> a >> b >>w;
        Node newNode(a, b, w);
        arr.push_back(newNode);
    }
    sort(arr.begin(), arr.end(), comp);
    Kruskal(arr, v);
    return 0;
}