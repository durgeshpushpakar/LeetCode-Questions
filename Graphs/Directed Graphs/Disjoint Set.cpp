#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
public:
int *parent, *rank;
DisjointSet(int n){
    parent=new int[n];
    rank=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}
int findParent(int i){
    if(parent[i]==i)return i;
    int x=findParent(parent[i]);
    parent[i]=x;
    return x;
}
void Union(int u, int v){
    u=findParent(u);
    v=findParent(v);
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
};
/********************/
/*vector implementation*/
class disjointSet{
    vector<int>parent, rank;
    int count;
  public:
    disjointSet(int n):parent(n), rank(n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        count=n;
    }
    int findParent(int i){
        if(parent[i]==i)return i;
        else return parent[i]=findParent(parent[i]);
    }
    void unionn(int u, int v){
        u=findParent(u);
        v=findParent(v);
        if(u==v)return;
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
        count--;
    }
    int getCount(){
        return count;
    }
};
