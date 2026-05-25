#include<iostream>
#include<algorithm>
using namespace std;
struct NODE{
    int val;
    NODE *left;
    NODE *right;
    NODE(int x):val(x),left(nullptr),right(nullptr){}
};
NODE* Insert(NODE *root, int val){
    if(root==nullptr) return new NODE(val);
    if(val<root->val) root->left=Insert(root->left,val);
    else root->right=Insert(root->right,val);
    return root;
}
int height=0;
void getDegree(NODE *root){
    if(root==nullptr||height==2) return;
    int curr=0;
    if(root->left!=nullptr) curr++;
    if(root->right!=nullptr) curr++;
    if(curr>height) height=curr;
    
    getDegree(root->left);
    getDegree(root->right);
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
    getDegree(root);
    cout<<height;
}