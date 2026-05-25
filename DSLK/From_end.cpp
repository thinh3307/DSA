#include<iostream>
using namespace std;
struct NODE{
    int info;
    NODE *pNext;
    NODE *pPrev;
};
struct LIST{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST&l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE*CreateEmptyNode(int x){
    NODE *p=new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    p->pPrev=NULL;
    return p;
}
void InsertTail(LIST& l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=p;
        l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        p->pPrev=l.pTail;
        l.pTail=p;
    }
}
int n_Th(LIST l, int k){
    NODE *p=l.pTail;
    int i=1;
    while(p!=NULL){
        if(i==k) return p->info;
        i++;
        p=p->pPrev;
    }
    return -1;
}

int main(){
    LIST l;
    CreateEmptyList(l);
    int n;
    cin>>n;
    if(n==0){
        
    }
    else{
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            InsertTail(l,CreateEmptyNode(x));
        }
    }
    int k;
    cin>>k;
    if(k<1) cout<<"-1";
    else if(k>n) cout<<"-1"; 
    else cout<<n_Th(l,k);
}