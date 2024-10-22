#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct BinaryTreeNode{
    int value = 0;
    BinaryTreeNode*left = NULL;
    BinaryTreeNode*right = NULL;
};
//创建二叉树，但这是个完全二叉树
void createBinaryTree(vector<int>nums,int index,BinaryTreeNode*&node){
    node = new BinaryTreeNode;
    node->value = nums[index];
    if(2*index+1<size(nums))createBinaryTree(nums,2*index+1,node->left);
    if(2*index+2<size(nums))createBinaryTree(nums,2*index+2,node->right);
}
//迭代写法的后序优先遍历
void DFS(BinaryTreeNode*root,vector<int>&res){
    stack<BinaryTreeNode*>stk;
    if(root)stk.push(root);
    while(!stk.empty()){
        BinaryTreeNode*node = stk.top();
        if(node!=NULL){
            stk.pop();
            stk.push(node);
            stk.push(NULL);
            if(node->right)stk.push(node->right);
            if(node->left)stk.push(node->left);
        }else {
            stk.pop();
            node = stk.top();
            stk.pop();
            res.push_back(node->value);
        }
    }
}
int main(){
    vector<int>nums={1,2,3,4,5,6,6,84,4,1,1,4,5,1,4,8,24,32,2};
    vector<int>res;
    BinaryTreeNode*root;
    createBinaryTree(nums,0,root);
    DFS(root,res);
    for(int i = 0;i<size(res);++i)cout<<res[i]<<" ";
    return 0;
}