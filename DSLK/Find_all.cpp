
#include <iostream>
#include <vector>
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

void TimKiem(LIST, int);

void TimKiem(LIST l, int k){
    NODE *p;
    int index=0;
    p=l.pHead;
    bool ktra=false;
    while(p!=NULL){
        if(p->info==k){
            ktra=true;
            cout<<index<<" ";
        }
        p=p->pNext;
        index++;
    }
    if(!ktra) cout<<"-1";
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
    TimKiem(L, k);
    return 0;
}