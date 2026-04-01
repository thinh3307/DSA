#include<iostream>
using namespace std;
typedef struct tagNode{
    int info;
    struct tagNode *pNext;
}NODE;
typedef struct tagList{
    NODE *pHead;
    NODE *pTail;
}LIST;
void CreateEmptyList(LIST& l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE* CreateNode(int x){
    NODE *p;
    p=new NODE;
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
int TimKiem(LIST l, int n){
    NODE *p;
    int index=0;
    p=l.pHead;
   while(p!=NULL){
    if(p->info==n) return index;
    p=p->pNext;
    index++;
   }
   return -1;
}
int TimKiem(LIST, int);


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
    cout << TimKiem(L, k);
    return 0;
}