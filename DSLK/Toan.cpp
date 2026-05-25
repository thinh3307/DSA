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

NODE* CreateEmptyNode(int x){
    NODE *p=new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pPrev=NULL;
    p->pNext=NULL;
    return p;
}

void CreateEmptyList(LIST& l){
    l.pHead=NULL;
    l.pTail=NULL;
}

void InsertHead(LIST& l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=p;
        l.pTail=p;
    }
    else{
       p->pNext=l.pHead;
       l.pHead->pPrev=p;
       l.pHead=p; 
    }
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

void PrintList(const LIST& l){
    NODE *p=l.pHead;
    while(p!=NULL){
        cout<<p->info;
        p=p->pNext;
    }
    cout<<"\n";
}

LIST Cong(const LIST& A, const LIST& B){
    LIST result;
    CreateEmptyList(result);
    NODE *p1=A.pTail;
    NODE *p2=B.pTail;
    int remember=0;
    while(p1!=NULL||p2!=NULL||remember>0){
        int v1=(p1!=NULL)?p1->info:0;
        int v2=(p2!=NULL)?p2->info:0;
        int tong=v1+v2+remember;
        remember=tong/10;
        int gtri=tong%10;
        NODE *temp=CreateEmptyNode(gtri);
        InsertHead(result,temp);
        
        if(p1!=NULL) p1=p1->pPrev;
        if(p2!=NULL) p2=p2->pPrev;
    }
    return result;
}

LIST Tru(const LIST& A, const LIST& B){
    LIST result;
    CreateEmptyList(result);
    NODE *p1=A.pTail;
    NODE *p2=B.pTail;
    int borrow=0;
    while(p1!=NULL||p2!=NULL){
        int v1=(p1!=NULL)?p1->info:0;
        int v2=(p2!=NULL)?p2->info:0;
        int hieu=v1-v2-borrow;
        
        if(hieu<0){
            hieu+=10;
            borrow=1;
        }
        else borrow=0;

        InsertHead(result,CreateEmptyNode(hieu));

        if(p1) p1=p1->pPrev;
        if(p2) p2=p2->pPrev;
    }
    while(result.pHead!=NULL && result.pHead->info==0 && result.pHead!=result.pTail){
        NODE *temp=result.pHead;
        result.pHead=result.pHead->pNext;
        result.pHead->pPrev=NULL;
        delete temp;
    }
    return result;
}
LIST NhanvoiChuSo(const LIST& l, int k){
    LIST result;
    CreateEmptyList(result);
    if(k==0){
        InsertTail(result,CreateEmptyNode(0));
        return result;
    }
    int remember=0;
    for(NODE *p=l.pTail;p!=NULL;p=p->pPrev){
        int t=p->info*k+remember;
        InsertHead(result,CreateEmptyNode(t%10));
        remember=t/10;
    }
    if(remember>0) InsertHead(result,CreateEmptyNode(remember));
    return result;

}
LIST Nhan(const LIST& A, const LIST& B){
    LIST result;
    CreateEmptyList(result);
    InsertTail(result,CreateEmptyNode(0));
    
    int soChusoKhong=0;

    for(NODE *p2=B.pTail;p2!=NULL;p2=p2->pPrev){
        LIST temp= NhanvoiChuSo(A,p2->info);

        for(int i=0;i<soChusoKhong;i++){
            InsertTail(temp,CreateEmptyNode(0));
        }

        LIST result_temp=result;
        result=Cong(result,temp);
        soChusoKhong++;
    }
    return result;
}
int Sosanh(const LIST& A, const LIST& B){
    int n1=0, n2=0;
    
    for(NODE *pA=A.pHead;pA;pA=pA->pNext) n1++;   
    for(NODE *pB=B.pHead;pB;pB=pB->pNext) n2++;

    if(n1>n2) return 1;
    if(n1<n2) return -1;

    NODE *p1=A.pHead, *p2=B.pHead;

    while(p1){
        if(p1->info>p2->info) return 1;
        if(p1->info<p2->info) return -1;
        p1=p1->pNext;
        p2=p2->pNext;
    }
    return 0;
}

LIST Chia(const LIST& A, const LIST& B){
    LIST result;
    CreateEmptyList(result);
    LIST soDu;
    CreateEmptyList(soDu);
    if(B.pHead->info==0) exit(1);

    NODE *pA=A.pHead;

    while(pA!=NULL){
        InsertTail(soDu,CreateEmptyNode(pA->info));

        while(soDu.pHead && soDu.pHead->info==0 && soDu.pHead!=soDu.pTail){
            NODE *temp=soDu.pHead;
            soDu.pHead=soDu.pHead->pNext;
            soDu.pHead->pPrev=NULL;
            delete temp;
        }
        int k=0;
        while(Sosanh(soDu,NhanvoiChuSo(B,k+1))>=0){
            k++;
            if(k==9) break;
        }
        InsertTail(result,CreateEmptyNode(k));
        LIST tich=NhanvoiChuSo(B,k);
        soDu=Tru(soDu,tich);
        pA=pA->pNext;
    }   
    while(result.pHead!=NULL && result.pHead->info==0 && result.pHead!=result.pTail){
        NODE *temp=result.pHead;
        result.pHead=result.pHead->pNext;
        result.pHead->pPrev=NULL;
        delete temp;
    }
    return result;
}