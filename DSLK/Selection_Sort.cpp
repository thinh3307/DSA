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
void CreateEmptyList(LIST& l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE* CreateEmptyNode(int x){
    NODE *p=new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void PrintList(LIST l){
    NODE *p=l.pHead;
    while(p!=NULL){
        cout<<p->info<<" ";
        p=p->pNext;
    }
}

void SelectionSort(LIST &l){
    NODE *p, *q, *min;
    p=l.pHead;
    while(p!=l.pTail){
        min=p;
        q=p->pNext;
        while(q!=NULL){
            if(q->info<min->info)  min=q;
                q=q->pNext;

        }
        swap(min->info,p->info);
        p=p->pNext;

    }
}

int main(){
    LIST l;
    CreateEmptyList(l);
    int n; cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        InsertTail(l,CreateEmptyNode(x));
    }
    SelectionSort(l);
    PrintList(l);
}