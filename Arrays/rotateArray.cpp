#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
void Reverse(vector<int>& arr, int i, int j){
    while(i<j){
        swap(arr[i++], arr[j--]);
    }
}
void rotate(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.end());
    Reverse(arr, 0, k-1);
    Reverse(arr, k, arr.size()-1);
}

int main(){

    return 0;
}