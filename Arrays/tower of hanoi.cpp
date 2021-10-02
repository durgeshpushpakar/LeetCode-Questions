#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
 long long toh(int n, int from, int to, int aux) {
    if(n==1){
        cout<<"move disk 1" <<" from rod "<<from << " to rod "<< to<<endl;
        return 1;
    }
    long long smallAns=toh(n-1, from, aux, to);
    cout<<"move disk "<<n<<" from rod "<< from<<" to rod "<< to<<endl;
    long long smallAns2=toh(n-1, aux, to, from);

    return smallAns+smallAns2+1;
}
int main(){

    return 0;
}