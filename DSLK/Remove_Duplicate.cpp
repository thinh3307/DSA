#include<iostream>
#include<string>
using namespace std;
struct NODE{
    char info;
    NODE *pNext;
    NODE *pPrev;
};
struct LIST{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST& l){
    l.pHead=NULL;
    l.pTail=NULL;
}
void Push(LIST& l, char x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    p->pPrev=l.pTail;
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void Pop(LIST& l){
    if(l.pHead==NULL) return;
    NODE *p=l.pTail;
    if(l.pHead==l.pTail){
        l.pHead=l.pTail=NULL;
    }
    else{
        l.pTail=l.pTail->pPrev;
        l.pTail->pNext=NULL;
    }
    delete p;
}

void solve(){
    string s;
    if(!(cin>>s)) return;
    LIST l;
    CreateEmptyList(l);
    for(char c:s){
        if(l.pTail!=NULL&&l.pTail->info==c){
            Pop(l);
        }
        else{
            Push(l,c);
        }
    }
    NODE *p=l.pHead;
    if(p==NULL) cout<<"";
    else{
        while(p!=NULL){
            cout<<p->info;
            p=p->pNext;
        }
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}