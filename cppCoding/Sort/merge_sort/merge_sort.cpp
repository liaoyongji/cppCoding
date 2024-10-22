#include<iostream>
#include<vector>
using namespace std;
//归并排序模板
void merge_sort(vector<int>&nums,int l,int r){
    if(l>=r)return;
    int mid = (l+r)/2;
    merge_sort(nums,l,mid);
    merge_sort(nums,mid+1,r);
    vector<int>tmp;
    int i = l;
    int j = mid+1;
    while(i<=mid&&j<=r){
        if(nums[i]<=nums[j])tmp.push_back(nums[i++]);
        else tmp.push_back(nums[j++]);
    }
    while(i<=mid)tmp.push_back(nums[i++]);
    while(j<=r)tmp.push_back(nums[j++]);
    for(i = l,j = 0;i<=r;++i,++j)nums[i] = tmp[j];
    tmp.clear();
}
int main(){
    vector<int>nums={1,0,-2,7,5,9,3,10,10};
    merge_sort(nums,0,size(nums)-1);
    for(int i = 0;i<size(nums);++i)cout<<nums[i]<<" ";
    return 0;
}