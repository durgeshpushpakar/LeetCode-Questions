#include<bits/stdc++.h>
using namespace std;
void heapSort(int *arr, int n){
    //insert elements in the heap one by one
    int j=1; // last index of heap
    while(j<n){
        int elementIdx=j;
        while(elementIdx>0){
            int parent=(elementIdx-1)/2;
            if(arr[elementIdx]<arr[parent]){
                swap(arr[elementIdx], arr[parent]);
                elementIdx=parent;
            }
            else break;
        }
        j++;
    }
    // remove minimum element from the array one by one
    int heapIdx=n-1;
    while(heapIdx>0){
        swap(arr[0], arr[heapIdx]);
        heapIdx--;
        int parent=0;
        int ch1=(2*parent)+1;
        int ch2=(2*parent)+2;
        while(ch1<=heapIdx){
            if(arr[ch1]<arr[parent] && arr[ch1]<arr[ch2]){
                swap(arr[ch1], arr[parent]);
                parent=ch1;
            }
            if(ch2<=heapIdx && arr[ch2]<arr[parent] && arr[ch2]<arr[ch1]){
                swap(arr[ch2], arr[parent]);
                parent=ch2;
            }
            else break;
            ch1=(2*parent)+1;
            ch2=(2*parent)+2;
        }
    }
}
int main()
{
    int arr[5]={15,6,3,2,20};
    heapSort(arr, 5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}