#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct NODE{
    int key;
    NODE *pNext;
    NODE(int k):key(k), pNext(nullptr){}
};
struct HashTable{
    int M;
    int n;
    double loadLimit;
    vector<NODE*> ht;
    HashTable(int m, double load):M(m),loadLimit(load),n(0){
        ht.resize(M,NULL);
    }

    void Insert(int k){
        if((double)(n+1)/M>loadLimit){
            return;
        }
        int index=k%M;
        NODE *newNode=new NODE(k);
        if(ht[index]==NULL) ht[index]=newNode;
        else{
            NODE *temp=ht[index];
            while(temp->pNext!=NULL){
                temp=temp->pNext;
            }
            temp->pNext=newNode;
        }
        n++;
    }
    void Search(int k){
        int index=k%M;
        NODE *temp=ht[index];
        int count=0;
        while(temp!=NULL){
            count++;
            if(temp->key==k){
                cout<<count<<endl;
                return;
            }
            temp=temp->pNext;
        }
        cout<<"KHONG"<<endl;
    }
};  

int main(){
    int m,n,n_search;
    double load;
    if(!(cin>>m>>load>>n)) return 0;
    HashTable ht(m,load);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        ht.Insert(k);
    }
    cin>>n_search;
    for(int i=0;i<n_search;i++){
        int k;
        cin>>k;
        ht.Search(k);
    }
}

