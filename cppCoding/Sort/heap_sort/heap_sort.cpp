#include<iostream>
#include<vector>
using namespace std;
void down(vector<int>&nums,int i,int bottom){
    int target = i;
    if(2*i+1<=bottom&&nums[2*i+1]>nums[target])target = 2*i+1;
    if(2*i+2<=bottom&&nums[2*i+2]>nums[target])target = 2*i+2;
    if(target!=i){
        swap(nums[target],nums[i]);
        down(nums,target,bottom);
    }
}
void heap_sort(vector<int>&nums){
    //造堆
    for(int i = (size(nums)-1)/2;i>=0;--i)down(nums,i,size(nums)-1);
    //排序
    for(int i = size(nums)-1;i>0;--i){
        swap(nums[i],nums[0]);
        down(nums,0,i-1);
    }
}
int main(){
    vector<int>nums={1,5,6,2,0,1,5,6,7,9,9,8,5,3,3,1,1,0,2,10,1};
    heap_sort(nums);
    for(int i = 0;i<size(nums);++i){
        cout<<nums[i]<<" ";
    }
    return 0;
}