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
NODE*CreateEmptyNode(int x){
    NODE *p=new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}
void InsertTail(LIST& l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=p;
        l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void searchNode(LIST l, int n){
    NODE *p=l.pHead;
    int i=0;
    while(p!=NULL){
        if(i==n/2){
            cout<<p->info;
            return;
        }
        p=p->pNext;
        i++;
    }
    
}
int main(){
    LIST l;
    CreateEmptyList(l);
    int n;
    cin>>n;
    if(n==0) cout<<"-1";
    else if (n==1){
        int x;
        cin>>x;
        cout<<x;
    }
    else{
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            InsertTail(l,CreateEmptyNode(x));
        }
    }
    searchNode(l,n);
}