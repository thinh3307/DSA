#include<iostream>
using namespace std;
struct NODE{
    int val;
    NODE *left;
    NODE *right;
    NODE(int x):val(x), left(nullptr),right(nullptr){}
};
NODE* Insert(NODE*root, int x){
    if(root==nullptr) return new NODE(x);
    if(x<root->val) root->left=Insert(root->left,x);
    else root->right=Insert(root->right,x);
    return root;
}
int countNode(NODE *root, int k){
    if(root==nullptr) return 0;
    int curr=0;
    if(root->left!=nullptr) curr++;
    if(root->right!=nullptr) curr++;
    int match=(curr==k)?1:0;
    return match+countNode(root->left,k)+countNode(root->right,k);
}
int main(){
    int n,k;
    if(!(cin>>n>>k)) return 0;
    NODE *root=nullptr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        root=Insert(root,val);
    }
    cout<<countNode(root,k);
}