#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr),right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r){}
};

class Solution {
    int preVal=INT_MIN;
    int currCount=0;
    int maxCount=0;
    vector<int> result;
public:

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
private:
    void inorder(TreeNode *node){
        if(!node) return;
        inorder(node->left);
        if(node->val==preVal) currCount++;
        else{
            currCount=1;
            preVal=node->val;
        }
        if(currCount>maxCount){
            maxCount=currCount;
            result={node->val};
        }
        else if(currCount==maxCount){
            result.push_back(node->val);
        }
        inorder(node->right);
    }
};