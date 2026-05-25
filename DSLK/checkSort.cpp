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
bool checkSort(LIST l){
    NODE *p=l.pHead;
    while(p!=NULL&&p->pNext!=NULL){
        NODE*q=p->pNext;
        if(p->info>q->info) return false;
        p=p->pNext;
    }
    return true;
}
int main(){
    LIST l;
    CreateEmptyList(l);
    int n;
    cin>>n;
    if(n==0) cout<<"YES";
    else if(n==1){
        int x;
        cin>>x;
        cout<<"YES";
    }
    else{
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            InsertTail(l,CreateEmptyNode(x));

        }
        bool kt=checkSort(l);
        if(kt) cout<<"YES";
        else cout<<"NO";
    }

}