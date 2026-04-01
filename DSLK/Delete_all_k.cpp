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
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}
void PrintList(LIST L){
    NODE*p=L.pHead;
    while(p!=NULL){
        cout<<p->info<<" ";
        p=p->pNext;
    }
}

void InsertTail(LIST &L, NODE *p){
    if(L.pHead==NULL){
        L.pHead=p;
        L.pTail=L.pHead;
    }
    else{
        L.pTail->pNext=p;
        L.pTail=p;
    }
}

void TimKiemVaXoa(LIST &, int);

void DeleteNode(LIST &l, NODE *p){
    if(l.pHead==NULL||p==NULL) return;

    if(p==l.pHead){
        l.pHead=l.pHead->pNext;
        if(l.pHead==NULL) l.pTail=NULL;
        delete p;
        return;
    }

    NODE *pPre=l.pHead;
    while(pPre!=NULL && pPre->pNext!=p){
        pPre=pPre->pNext;
    }
    if(pPre!=NULL){
        pPre->pNext=p->pNext;
        if(p==l.pTail) l.pTail=pPre;
        delete p;
    }  
}
void TimKiemVaXoa(LIST &l, int k){
    NODE *p=l.pHead;
    while(p!=NULL){
        NODE *next=p->pNext;
        if(p->info==k) DeleteNode(l,p);
        p=next;
    }
}

int main(){
    LIST L;
    CreateEmptyList(L);
    int n; cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        InsertTail(L,CreateEmptyNode(x));
    }
    int k; cin>>k;
    TimKiemVaXoa(L,k);
}