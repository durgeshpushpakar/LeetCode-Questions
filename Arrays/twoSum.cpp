#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>umap;
    unordered_map<int, int>freq;
    vector<int>ans{0, 0};
    cout<<"array: ";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
        umap[nums[i]]=i;
        freq[nums[i]]++;
    }
    cout<<endl<<endl;
    cout<<"freq: "<<freq.count(target-nums[1])<<endl;
    cout<<"umap: "<<umap.at(target-nums[1])<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<"i: "<<i<<endl;
        int required=target-nums[i];
        freq[nums[i]]--;
        cout<<"required: "<<required<<endl;
        cout<<"freq: " <<freq.count(required)<<endl;
        if(freq[required]>=1){
            ans[0]=i;
            ans[1]=umap.at(required);
            return ans;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr{3,2,4};
    vector<int>ans=twoSum(arr, 6);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}