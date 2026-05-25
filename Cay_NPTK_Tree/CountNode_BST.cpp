#include<iostream>
using namespace std;
struct  NODE
{
    int val;
    NODE *left;
    NODE *right;
    NODE(int x): val(x),left(nullptr),right(nullptr){}
};

NODE* Insert(NODE *root, int x){
    if(root==nullptr) return new NODE(x);
    if(x<root->val) root->left=Insert(root->left,x);
    else root->right=Insert(root->right,x);
    return root;
}

int countNode(NODE *root, int k, int currLevel){
    if(root==nullptr) return 0;
    if(currLevel==k) return 1;
    return countNode(root->left,k,currLevel+1)+countNode(root->right,k,currLevel+1);
}
int main(){
    int n,k;
    if(!(cin>>n>>k)) return 0;
    NODE *root=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root=Insert(root,x);
    }

    cout<<countNode(root,k,0);
}
