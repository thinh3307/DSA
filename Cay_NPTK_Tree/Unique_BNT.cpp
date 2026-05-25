#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *l, TreeNode *r):val(x),left(l),right(r){}
};
class Solution{
public:
    vector<TreeNode*>generatesTree(int n){
        if(n==0) return {};
        return buildTree(1,n);
    }
private:
    vector<TreeNode*> buildTree(int start, int end){
        vector<TreeNode*> all;
        if(start>end){
            all.push_back(nullptr);
            return all;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*>leftTree=buildTree(start,i-1);
            vector<TreeNode*>rightTree=buildTree(i+1,end);
            for(TreeNode *left: leftTree){
                for(TreeNode *right:rightTree){
                TreeNode *root=new TreeNode(i);
                root->left=left;
                root->right=right;
                all.push_back(root);
                }
            }
        }
        return all;
    }

};