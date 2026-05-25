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
    bool validBST(TreeNode *root){
        return validate(root,LLONG_MIN,LLONG_MAX);
    }
private:
    bool validate(TreeNode *node,long long minval, long long maxval){
        if(node==nullptr) return true;
        if(node->val<=minval||node->val>=maxval) return false;
        return validate(node->left,minval,node->val)&&validate(node->right,node->val,minval);

    }
};