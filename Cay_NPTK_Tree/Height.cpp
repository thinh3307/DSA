#include<iostream>
#include<algorithm>
#include<queue>
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

int getHeight(NODE *root){
    if(root==nullptr) return -1;
    queue<NODE*> q;
    q.push(root);
    int height=-1;
    while(!q.empty()){
        int nodeCount=q.size();
        if(nodeCount>0) height++;
        while(nodeCount>0){
            NODE *p=q.front();
            q.pop();
            if(p->left!=nullptr) q.push(p->left);
            if(p->right!=nullptr) q.push(p->right);
            nodeCount--;
        }
    }
    return height;
}
int main(){
    int n;
    if(!(cin>>n)) return 0;
    NODE *root=nullptr;
    while(n--){
        int val;
        cin>>val;
        root=Insert(root,val);
    }
    cout<<getHeight(root);
}