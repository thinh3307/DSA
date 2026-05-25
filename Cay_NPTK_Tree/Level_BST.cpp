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
    if(val<root->val){
        root->left=Insert(root->left,val);
    }
    else{
        root->right=Insert(root->right,val);
    }
    return root;
}

int findLevel(NODE *root, int x, int level){
    if(root==nullptr) return -1;
    if(root->val==x) return level;
    if(x<root->val) return findLevel(root->left,x,level+1);
    else return findLevel(root->right,x,level+1);
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
    cout<<findLevel(root,x,0);
}