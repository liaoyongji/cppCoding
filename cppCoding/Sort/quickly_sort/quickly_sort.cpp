#include<iostream>
#include<vector>
using namespace std;
//快速排序模板
void quickly_sort(vector<int>&nums,int l,int r){
    if(l>=r)return;
    int x = nums[(l+r)/2];
    int i = l-1;
    int j = r+1;
    while(i<j){
        do i++;while(nums[i]<x);
        do j--;while(nums[j]>x);
        if(i<j){
            int swapNum = nums[i];
            nums[i] = nums[j];
            nums[j] = swapNum;
        }
    }
    quickly_sort(nums,l,j);
    quickly_sort(nums,j+1,r);
}
int main(){
    vector<int>nums = {5,2,0,1,0,1,1,0,3,-7,8,10,-9};
    quickly_sort(nums,0,size(nums)-1);
    for(int i = 0;i<size(nums);++i)cout<<nums[i]<<" ";
    return 0;
}