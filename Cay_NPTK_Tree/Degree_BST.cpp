#include<iostream>
#include<vector>
using namespace std;
struct NODE{
    int val;
    NODE *left;
    NODE *right;
    NODE(int v):val(v),left(nullptr),right(nullptr){}
};
NODE *Insert(NODE *root, int val){
    if(root==nullptr) return new NODE(val);
    if(val<root->val) root->left=Insert(root->left,val);
    else root->right=Insert(root->right,val);
    return root;
}
int findDegree(NODE *root, int x){
    if(root==nullptr) return -1;
    if(root->val==x){
        int degree=0;
        if(root->left!=nullptr) degree++;
        if(root->right!=nullptr) degree++;
        return degree;
    }   
    if(x<root->val) return findDegree(root->left,x);
    else return findDegree(root->right,x);
}
int main(){
    int n,x;
    if(!(cin>>n)) return 0;
    NODE *root=nullptr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        root=Insert(root,val);
    }
    cin>>x;
    cout<<findDegree(root,x);
}
