#include<iostream>
using namespace std;
typedef struct tagTNODE{
    int Key;
    struct tagTNODE *pLeft;
    struct tagTNODE *pRight;
}TNODE;

typedef TNODE *TREE;
void CreateEmptyTree(TREE& T){
    T=NULL;
}
TNODE* CreateEmptyNode(int x){
    TNODE *p=new TNODE;
    if(p==NULL) exit(1);
    else{
        p->Key=x;
        p->pRight=NULL;
        p->pLeft=NULL;
    }
    return p;
}
int InsertNODE(TREE& T, int x){
    if(T!=NULL){
        if(T->Key==x) return 0;
        else if(T->Key>x) return InsertNODE(T->pLeft,x);
        else return InsertNODE(T->pRight,x);
    }
    T=CreateEmptyNode(x);
    return 1;
}
int main(){

}