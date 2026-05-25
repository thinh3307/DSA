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
public:
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*>st;
        TreeNode *curr=root;
        while(curr||!st.empty()){
             while(curr){
                st.push(curr);
                curr=curr->left;
             }
             curr=st.top();
             st.pop();
             k--;
             if(k==0) return curr->val;
             curr=curr->right;
        }
        return -1;
    }
};