#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr),right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r){}
};

class BSTIterator {
    stack<TreeNode*> st;
    void pushLeft(TreeNode *node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode *root=st.top(); 
        st.pop();
        pushLeft(root->right);
        return root->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};