/*
给你一个长度为 n 的整数数组 nums 和一个正整数 k 。
一个数组的 能量值 定义为：
    如果 所有 元素都是依次 连续 且 上升 的，那么能量值为 最大 的元素。否则为 -1 。
    你需要求出nums中所有长度为k的子数组的能量值。
请你返回一个长度为n-k+1的整数数组 results,其中 results[i] 是子数组nums[i..(i + k - 1)] 的能量值。
*/
#include<iostream>
#include<vector>
using namespace std;
bool isVail(vector<int>&nums,int l,int r){
    for(int i = l;i<r;++i)
        if(nums[i+1]!=nums[i]+1)return false;
    return true;
}
vector<int>slidingWindow(vector<int>&nums,int k){
    int l = 0;
    vector<int>res;
    for(int r = 0;r<size(nums);++r){
        if(r-l+1>=k){
            if(isVail(nums,l,r))
                res.push_back(nums[r]);
            else res.push_back(-1);
            ++l;
        }
    }
    return res;
}
int main(){
    int n;
    int k;
    vector<int>nums;
    cin>>n>>k;
    for(int i = 0;i<n;++i){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    vector<int>res = slidingWindow(nums,k);
    for(int i = 0;i<size(res);++i){
        cout<<res[i]<<" ";
    }
    return 0;
}