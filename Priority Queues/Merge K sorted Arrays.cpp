#include<bits/stdc++.h>
using namespace std;
// element, i, j
class Triplet{
    public:
    int e, i, j;
    Triplet(int a, int b, int c){
        e=a,i=b,j=c;
    }
};
class comp{
    public:
    bool operator()(Triplet &a, Triplet &b){
        return a.e>b.e;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    vector<int>ans;
    priority_queue<Triplet, vector<Triplet>, comp>pq;
    for(int i=0;i<input.size();i++){
        Triplet temp(input[i]->at(0), i, 0);
        pq.push(temp);
    }
    while(!pq.empty()){
        Triplet top=pq.top();
        pq.pop();
        ans.push_back(top.e);
        if(top.j+1<input[top.i]->size()){            
            Triplet temp(input[top.i]->at(top.j+1), top.i, top.j+1);
            pq.push(temp);
        }
    }
    return ans;
}
int main()
{
    
    return 0;
}