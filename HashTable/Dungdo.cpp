#include<iostream>
#include<vector>
using namespace std;
struct NODE{
    int info;
    NODE *pNext;
    NODE(int x):info(x),pNext(nullptr){}
};
struct HashTable{
    int M;
    vector<NODE*> buckets;
    HashTable(int size):M(size){
        buckets.resize(M,nullptr);
    }
    bool checkCollision(int key){
        int index=key%M;
        if(buckets[index]==nullptr){
            buckets[index]=new NODE(key);
            return false;
        }
        else{
            NODE *newNODE=new NODE(key);
            newNODE->pNext=buckets[index];
            buckets[index]=newNODE;
            return true;
        }
    }
};

int main(){
    int n,m;
    if(!(cin>>n>>m)) return 0;
    HashTable tb(m);
    int count =0;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(tb.checkCollision(val)) count++;
    }
    double rate=(double)count/n;
    if(rate>0.33) cout<<"BAD";
    else cout<<"GOOD";
}
