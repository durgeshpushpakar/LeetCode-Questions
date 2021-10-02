#include<iostream>
using namespace std;
void printNos(int N)
{
    if(N==1){
        cout<<N<<endl;
        return;
    }
    printNos(N-1);
    cout<<N<<endl;
}