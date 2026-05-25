#include<iostream>
using namespace std;
struct NODE{
    int info,col,row;
    NODE *pNext;
    NODE *pPrev;
};
struct LIST{
    NODE *pHead;
    NODE *pTail;
    int cot,hang;
};
void CreateEmptyMatrix(LIST& M, int r, int c){
    M.cot=c;
    M.hang=r;
    M.pHead=NULL;
    M.pTail=NULL;
}

NODE* CreateEmptyNODE(int r, int c, int val){
    NODE *p=new NODE;
    if(p==NULL) exit(1);
    p->info=val;
    p->col=c;
    p->row=r;
    p->pNext=NULL;
    p->pPrev=NULL;
    return p;
}

void InsertMatrix(LIST& M, NODE* p){
    if(M.pHead==NULL){
        M.pHead=p;
        M.pTail=p;
    }
    else{
        M.pTail->pNext=p;
        M.pTail=p;
    }
}

int getSum(LIST l, int r, int c){
    NODE *p=l.pHead;
    while(p!=NULL){
        if(p->row==r && p->col==c) return p->info;
        p=p->pNext;
    }
    return 0;
}

LIST Cong(const LIST& l1, const LIST& l2){
    LIST result;
    CreateEmptyMatrix(result,l1.cot,l2.hang);
    for(int i=0;i<l1.hang;i++){
        for(int j=0;j<l1.cot;j++){
            int sum=getSum(l1,i,j)+getSum(l2,i,j);
            if(sum!=0) InsertMatrix(result,CreateEmptyNODE(i,j,sum));
        }
    }
    return result;
}

LIST Nhan(const LIST& l1, const LIST& l2){
    LIST result;
    CreateEmptyMatrix(result,l1.hang, l2.cot);
    for(int i=0;i<l1.hang;i++){
        for(int j=0;j<l2.cot;j++){
            int temp=0;
            for(int k=0;k<l1.cot;k++) temp+=getSum(l1,i,k)*getSum(l2,k,j);
            if(temp!=0) InsertMatrix(result,CreateEmptyNODE(i,j,temp));
        }
    }
    return result;
}

void PrintMatrix(const LIST& M){
    NODE *p=M.pHead;

}
int main(){
    LIST M1, M2;
    int r1,c1,r2,c2;
    cin>>r1>>c1;
    CreateEmptyMatrix(M1,r1,c1);
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            int val;
            if(cin>>val) InsertMatrix(M1,CreateEmptyNODE(r1,c1,val));
        }
    }
    cin>>r2>>c2;
    CreateEmptyMatrix(M2,r2,c2);
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            int val;
            if(cin>>val) InsertMatrix(M2,CreateEmptyNODE(r2,c2,val));
        }
    }
    
}

