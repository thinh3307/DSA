#include<iostream>
using namespace std;
struct NODE{
    int info;
    NODE *pNext;
};
struct LIST{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST&l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE* CreateEmptyNode(int x){
    NODE*p=new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}
void InsertTail(LIST&l, NODE*p){
    if(l.pHead==NULL){
        l.pHead=p;
        l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void PrintList(LIST l){
    NODE *p=l.pHead;
    while(p!=NULL){
        cout<<p->info<<" ";
        p=p->pNext;
    }
}
void DeleteNode(LIST&l,NODE *p){
    if(l.pHead==NULL||p==NULL) return;
    NODE *pPre=l.pHead;
    while(pPre!=NULL&&pPre->pNext!=p){
        pPre=pPre->pNext;
    }
    if(pPre!=NULL){
        pPre->pNext=p->pNext;
        if(p==l.pTail) l.pTail=pPre;
        delete p;
    }
}
int main(){
    LIST l;
    CreateEmptyList(l);
    int n; cin>>n;
    int x;
    if(n==0) cout<<"";
    else if(n==1){
        cin>>x;
        cout<<x;
    }
    else{
        for(int i=0;i<n;++i){
            cin>>x;
            InsertTail(l,CreateEmptyNode(x));
        }
    }
    NODE *p=l.pHead;
    while(p!=NULL){
        NODE*q=p->pNext;
        while(q!=NULL){
            if(q->info==p->info){
                NODE *temp=q;
                q=q->pNext;
                DeleteNode(l,temp);
            }
            else{
                q=q->pNext;
            }

        }
        p=p->pNext;
    }
    PrintList(l);
}