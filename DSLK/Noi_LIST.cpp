#include<bits/stdc++.h>
using namespace std;
struct NODE{
    int info;
    NODE *pNext;
};
struct LIST{
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptyList(LIST& L){
    L.pHead=NULL;
    L.pTail=NULL;
}

NODE* CreateEmptyNode(int x){
    NODE *p=new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}

void InsertTail(LIST &L, NODE *p){
    if(L.pHead==NULL){
        L.pTail=p;
        L.pHead=L.pTail;
    }
    else{
        L.pTail->pNext=p;
        L.pTail=p;
    }
}

void PrintList(LIST l){
    NODE *p=l.pHead;
    while(p!=NULL){
        cout<<p->info<<" ";
        p=p->pNext;
    }
}

void Noi(LIST& L, LIST M){
    if(L.pHead==NULL){
        L.pHead=M.pHead;
        return;
    }
    else{
        L.pTail->pNext=M.pHead;
    }
}

int main(){
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        InsertTail(L1,CreateEmptyNode(x));
    }
    int m; cin>>m;
    int k;
    for(int i=0;i<m;i++){
        cin>>k;
        InsertTail(L2,CreateEmptyNode(k));
    }
    Noi(L1,L2);
    PrintList(L1);
}