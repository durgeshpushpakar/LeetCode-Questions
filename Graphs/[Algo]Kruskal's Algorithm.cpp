#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int source, dest, weight;
    Edge(){}
    Edge(int s, int d, int w){
        source=s;
        dest=d;
        weight=w;
    } 
};
bool comparator(Edge &e1, Edge &e2){
    return (e1.weight<e2.weight);
}
bool parent_find(vector<int>&parent, int src, int dest){
    int p1=src, p2=dest;
    while(parent[p1]!=p1)p1=parent[p1];
    while(p2!=parent[p2])p2=parent[p2];
    return p1!=p2;
}
vector<Edge>kruskalAlgo(vector<Edge>arr, int n){
    int e=arr.size();
    vector<Edge>ans;
    sort(arr.begin(), arr.end(), comparator);
    int count=0;
    vector<int>parent(n);
    for(int i=0;i<n;i++)parent[i]=i;
    for(int i=0;i<e && count<n-1;i++){
        Edge current=arr[i];
        if(parent_find(parent, current.source, current.dest)){
            ans.push_back(current);
            count++;
            parent[current.dest]=current.source;
        }
        else continue;
    }
    return ans;
}
int main(){
    int n, e;cin>>n>>e;
    vector<Edge>arr;
    for(int i=0;i<e;i++){
        int a,b,c;cin>>a>>b>>c;
        Edge temp(a,b,c);
        arr.push_back(temp);
    }
    vector<Edge>output=kruskalAlgo(arr, n);
    for(int i=0;i<output.size();i++){
        int a, b;
        if(output[i].source>=output[i].dest){
            a=output[i].dest;
            b=output[i].source;
        }
        else{
            b=output[i].dest;
            a=output[i].source;
        }
        cout<<a<<" "<<b<<" "<<output[i].weight<<endl;
    }
    return 0;
}
