#include <iostream>
using namespace std;
typedef struct TagNode{
    int info;
    struct TagNode *pNext;
}NODE;
typedef struct tagList{
    NODE *pHead;
    NODE *pTail;

}LIST;
void CreateEmptyList(LIST&l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE* CreateNode(int x){
    NODE *p;
    p= new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}
void InsertTail(LIST& l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=p;
        l.pTail=l.pHead;

    }
    else {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void DeleteTail(LIST& l){
    if(l.pHead==NULL) return;
    if(l.pHead==l.pTail){
        delete l.pHead;
        l.pHead = NULL; 
        l.pTail = NULL; 
        return;
    }
    NODE *pPre=NULL;
    NODE *pCur=l.pHead;
    while(pCur->pNext!=NULL){
        pPre=pCur;
        pCur=pCur->pNext;
    }
    pPre->pNext=NULL;
    l.pTail=pPre;
    delete pCur;
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
    for(int i=0;i<n;i++) DeleteTail(L);
    PrintList(L);
    return 0;
}

