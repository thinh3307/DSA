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

void InsertTail(LIST& l, NODE *p){
    if(l.pHead==NULL){
        l.pTail=p;
        l.pHead=l.pTail;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}

void PrintList(LIST l){
    NODE *p=l.pHead;
    while (p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->pNext;
    }
    
}
void TronDSLK(LIST &l1, LIST &l2, LIST &l3){
    CreateEmptyList(l3);
    NODE *p1=l1.pHead;
    NODE *p2=l2.pHead;
    while(p1!=NULL&&p2!=NULL){
        if(p1->info<=p2->info){
            InsertTail(l3,CreateEmptyNode(p1->info));
            p1=p1->pNext;
        }
        else{
            InsertTail(l3,CreateEmptyNode(p2->info));
            p2=p2->pNext;
        }
    }
    while(p1!=NULL){
        InsertTail(l3,CreateEmptyNode(p1->info));
        p1=p1->pNext;
    }
    while(p2!=NULL){
        InsertTail(l3,CreateEmptyNode(p2->info));
        p2=p2->pNext;
    }

}

int main(){
    LIST l1, l2, l3;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        CreateEmptyList(l1);
        int n,m;
        cin>>n>>m;
        int x;
        for(int j=0;j<n;j++){
            cin>>x;
            InsertTail(l1,CreateEmptyNode(x));
        }
        CreateEmptyList(l2);
        for(int j=0;j<m;j++){
            cin>>x;
            InsertTail(l2,CreateEmptyNode(x));
        }
        TronDSLK(l1,l2,l3);
        PrintList(l3);
        cout<<"\n";
    }
}