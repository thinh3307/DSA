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

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
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

NODE *TimKiem(LIST l, int k){
    NODE *p;
    p=l.pHead;
    while(p!=NULL&&p->info!=k){
        p=p->pNext;
    }
    return p;
}
void InsertNode(LIST &l, NODE *p){
    
}
void TimKiemVaThem(LIST &l, int k){
    NODE *p=TimKiem(l,k);
    NODE *newNODE=CreateNode(1999);
    if(p!=NULL){
        newNODE->pNext=p->pNext;
        p->pNext=newNODE;
        if(p==l.pTail){
            l.pTail=newNODE;
        }

    }
    else{
        InsertTail(l,newNODE);

    }
    PrintList(l);


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
    TimKiemVaThem(L, k);
    return 0;
}
