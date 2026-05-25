#include<iostream>
#include<string>
using namespace std;
struct NODE{
    char info;
    NODE*pNext;
    NODE*pPrev;
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
    if(l.pHead==NULL) l.pHead=l.pTail=p;
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void solve(){
    string s;
    if(!(cin>>s)) return;
    
    LIST l;
    CreateEmptyList(l);
    int balance=0;
    for(char c:s){
        if(c=='('){
            if(balance>0){
                Push(l,c);
            }
            balance++;
        }
        else{
            balance--;
            if(balance>0) Push(l,c);
        }
    }
    NODE*p=l.pHead;
    if(p==NULL){
        cout<<"";
    }
    else{
        while (p!=NULL)
        {
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
}