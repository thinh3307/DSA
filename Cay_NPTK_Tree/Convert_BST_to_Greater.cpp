#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr),right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r){}
};

class Solution{
    int sum=0;
public:
    TreeNode* convertBST(TreeNode *root){
        reverseInorder(root);
        return root;
    }
private:
    void reverseInorder(TreeNode *node){
        if(!node) return;
        reverseInorder(node->right);
        sum+=node->val;
        node->val=sum;
        reverseInorder(node->left);
    }
};
void printInorder(TreeNode* node) {
    if (!node) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Xây cây từ mảng (như LeetCode, -1 = null)
TreeNode* buildTree(vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nums.size()) {
        TreeNode* curr = q.front(); q.pop();

        // Con trái
        if (i < nums.size()) {
            if (nums[i] != -1) {
                curr->left = new TreeNode(nums[i]);
                q.push(curr->left);
            }
            i++;
        }

        // Con phải
        if (i < nums.size()) {
            if (nums[i] != -1) {
                curr->right = new TreeNode(nums[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}

// ===== MAIN =====
int main() {
    vector<int> nums = {4,1,6,0,2,5,7,-1,-1,3,-1,-1,-1,-1,8};

    TreeNode* root = buildTree(nums);

    cout << "Truoc khi convert (inorder): ";
    printInorder(root);
    cout << endl;

    Solution sol;
    sol.convertBST(root);

    cout << "Sau khi convert  (inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}