#include<iostream>
using namespace std;
struct NODE{
    int val;
    NODE *left;
    NODE *right;
    NODE(int x):val(x),left(nullptr),right(nullptr){}
};
NODE* Insert(NODE *root, int x){
    if(root==nullptr) return new NODE(x);
    if(x<root->val) root->left=Insert(root->left,x);
    else root->right=Insert(root->right,x);
    return root;
}
int countLeaf(NODE *root){
    if(root==nullptr) return 0;
    if(root->left==nullptr&&root->right==nullptr) return 1;
    return countLeaf(root->left)+countLeaf(root->right);
}
int main(){
    int n;
    if(!(cin>>n)) return 0;
    NODE *root=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root=Insert(root,x);
    }
    cout<<countLeaf(root);
}