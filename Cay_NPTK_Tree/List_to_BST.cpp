#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *p): val(x), next(p){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr),right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r){}
};

class Solution{
    TreeNode* sortedListtoBST(ListNode *head){
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode* prev=nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev) prev->next=nullptr;
        TreeNode *node=new TreeNode(slow->val);
        node->left=sortedListtoBST(head);
        node->right=sortedListtoBST(slow->next);
        return node;
    }
};