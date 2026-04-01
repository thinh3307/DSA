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
void CreateEmptyList(LIST &L){
    L.pHead=NULL;
    L.pTail=NULL;
}
NODE* CreateEmptyNode(int x){
    NODE *p=new NODE;
    if (p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}
void PrintList(LIST L){
    NODE *p=L.pHead;
    while(p!=NULL){
        cout<<p->info<<" ";
        p=p->pNext;
    }
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
void Reversesell(LIST &L){
    NODE *pPre=NULL;
    NODE *pCurr=L.pHead, *pTemp=NULL, *first=L.pHead;


    while(pCurr!=NULL){
        pTemp=pCurr->pNext;
        pCurr->pNext=pPre;
        pPre=pCurr;
        pCurr=pTemp;

    }
    L.pHead=pPre;
    L.pTail=first;
}

int main(){
    LIST L;
    CreateEmptyList(L);
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        InsertTail(L,CreateEmptyNode(x));
    }
    Reversesell(L);
    PrintList(L);
}
