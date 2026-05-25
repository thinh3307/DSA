#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r){}
};
class Solution{
public:
    TreeNode *first=nullptr;
    TreeNode *second=nullptr;
    TreeNode *prev=nullptr;
    void recoverTree(TreeNode *root){
        inorder(root);
        swap(first->val,second->val);
    }
private:
    void inorder(TreeNode *p){
        if(!p) return;
        inorder(p->left);
        if(prev&&prev->val>p->val){
            if(!first) first=prev;
            second=p;
        }
        prev=p;
        inorder(p->right);
    }
};