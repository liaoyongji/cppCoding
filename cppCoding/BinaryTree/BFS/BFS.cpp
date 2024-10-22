#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>res;
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
void BFS(BinaryTreeNode*root){
    queue<BinaryTreeNode*>que;
    if(root)que.push(root);
    int layerNum = 1;
    while(!que.empty()){
        int nextLayNum = 0;
        vector<int>ChildRes;
        for(int i = 0;i<layerNum;++i){
            BinaryTreeNode*node = que.front();
            que.pop();
            ChildRes.push_back(node->value);
            if(node->left){
                ++nextLayNum;
                que.push(node->left);
            }
            if(node->right){
                ++nextLayNum;
                que.push(node->right);
            }
        }
        res.push_back(ChildRes);
        layerNum = nextLayNum;
        ChildRes.clear();
    }
}
int main(){
    vector<int>nums={1,2,3,4,5,6,6,84,4,1,1,4,5,1,4,8,24,32,2};
    BinaryTreeNode*root;
    createBinaryTree(nums,0,root);
    BFS(root);
    for(int i = 0;i<size(res);++i){
        for(int j = 0;j<size(res[i]);++j)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}