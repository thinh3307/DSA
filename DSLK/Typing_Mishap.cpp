    #include<iostream>
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
    void CreateEmptyList(LIST&l){
        l.pHead=NULL;
        l.pTail=NULL;
    }
    NODE*CreateEmptyNode(char x){
        NODE *p=new NODE;
        if(p==NULL) exit(1);
        p->info=x;
        p->pNext=NULL;
        p->pPrev=NULL;
        return p;
    }
    void Push(LIST&l, char x){
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
    void Pop(LIST&l){
        if(l.pTail==NULL) return;
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
    void addChar(LIST&l, char x){
        if(x=='#'){
            Pop(l);
        }
        else{
            Push(l,x);
        }
    }
    bool isEqual(LIST l1, LIST l2){
        NODE *p1=l1.pHead; NODE *p2=l2.pHead;
        while(p1&&p2){
            if(p1->info!=p2->info) return false;
            p1=p1->pNext;
            p2=p2->pNext;
        }
        return (p1 == NULL && p2 == NULL);
    }
    void Input(LIST&l){
        string s;
        if(!(cin>>s)) return;
        for(char c:s) addChar(l,c);
    }
    int main(){
        LIST l1,l2;
        CreateEmptyList(l1);
        CreateEmptyList(l2);
        Input(l1);
        Input(l2);
        if(isEqual(l1,l2)) cout<<"YES";
        else cout<<"NO";

    }