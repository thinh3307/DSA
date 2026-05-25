#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,M;
    if(!(cin>>n>>M)) return 0;
    vector<int> hastable(M,-1);
    vector<int> collision(M,0);
    vector<int>keys(n);
    for(int i=0;i<n;i++){
        cin>>keys[i];
    }
    for(int key:keys){
        for(int i=0;i<M;i++){
            int pos=(key%M+i)%M;
            if(hastable[pos]==-1){
                hastable[pos]=key;
                break;
            }
            else collision[pos]++;
        }
    }
    int maxCollision=0;
    for(int count:collision){
        if(count>maxCollision) maxCollision=count;
    }
    bool first=true;
    for(int i=0;i<M;i++){
        if(collision[i]==maxCollision&&maxCollision>0){
            if(!first) cout<<" ";
            cout<<i;
            first=false;
        }
    }
    
}