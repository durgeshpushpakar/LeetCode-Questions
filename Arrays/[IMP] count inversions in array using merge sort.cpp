#define ll long long
class Solution{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(ll arr[], ll left, ll right, ll &ans){
        ll mid=left+((right-left)>>1);
        ll i=left, j=mid+1;
        vector<ll>temp;
        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                ans+=mid-i+1;
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid)temp.push_back(arr[i++]);
        while(j<=right)temp.push_back(arr[j++]);
        ll l=0;
        for(ll k=left;k<=right;k++){
            arr[k]=temp[l++];
        }
    }
    void mergeSort(ll arr[], ll left, ll right, ll &ans){
        if(left>=right)return;
        ll mid=left+((right-left)>>1);
        mergeSort(arr, left, mid, ans);
        mergeSort(arr, mid+1, right, ans);
        merge(arr, left, right, ans);
    }
    long long int inversionCount(long long arr[], long long n)
    {
        ll ans=0;
        mergeSort(arr, 0, n-1, ans);
        return ans;
    }
};