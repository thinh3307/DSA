
#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void InsertTail(LIST &l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=p;
        l.pTail=l.pHead;
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
    cout<<"\n";
}
NODE* TimKiem(LIST l, int k) {
    NODE *p = l.pHead;
    while (p != NULL) {
        if (p->info == k) return p;
        p = p->pNext;
    }
    return NULL;
}
void DeleteNODE(LIST &l, NODE *p){
    if(l.pHead==NULL||p==NULL) return;

    if(p==l.pHead){
        l.pHead=l.pHead->pNext;
        if(l.pHead==NULL) l.pTail=NULL;
        delete p;
        return;
    }

    NODE *pPre = l.pHead;
    while(pPre!=NULL&&pPre->pNext!=p){
        pPre=pPre->pNext;
    }
    if(pPre!=NULL){
        pPre->pNext=p->pNext;
        if(p==l.pTail) l.pTail=pPre;
        delete p;
    }

}

void TimKiemVaXoa(LIST &l, int k){
    NODE *p=TimKiem(l,k);
    if(p==NULL) cout<<"-1";
    else{
        DeleteNODE(l,p);
        PrintList(l);
    }
    
}



int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    int k; cin >> k;
    TimKiemVaXoa(L, k);
    return 0;
}
