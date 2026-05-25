#include<iostream>
#include<string>
#include<sstream>
using namespace std;
struct NODE{
    long long info;
    NODE *pNext;
    NODE *pPrev;
};
struct LIST{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST& l){
    l.pHead=l.pTail=NULL;
}
void Push(LIST& l, long long x){
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
long long Pop(LIST& l, bool& temp){
    if(l.pTail==NULL){
        temp=true;
        return 0;
    }
    NODE *p=l.pTail;
    long long val=p->info;
    if(l.pHead==l.pTail){
        l.pHead=l.pTail=NULL;
    }
    else{
        l.pTail=l.pTail->pPrev;
        l.pTail->pNext=NULL;
    }
    delete p;
    return val;
}
void solve(){
    string line;
    if(!getline(cin,line)) return;
    stringstream ss(line);
    LIST l;
    string token;
    CreateEmptyList(l);
    bool error=false;
    while(ss>>token){
        if(token=="+"||token=="-"||token=="x"||token==":"){
            long long b=Pop(l,error);
            long long a=Pop(l,error);
            if(error) break;
            long long result;
            if(token=="+") result=a+b;
            else if(token=="-")result=a-b;
            else if(token=="x")result=a*b;
            else{
                if(b==0){
                    error=true;
                    break;
                }
                result=a/b;
            }
            Push(l,result);
        }
        else{
            try{
                long long num=stoll(token);
                Push(l,num);
            }catch(...){
                error=true;
                break;
            }
        }
    }
    if(error||l.pHead==NULL||l.pHead!=l.pTail){
        cout<<"KHONG HOP LE"<<endl;
    }
    else cout<<l.pTail->info<<endl;
}
int main(){
    solve();
}