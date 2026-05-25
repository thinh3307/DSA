#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<int> count(m,0);
    for(int i=0;i<n;i++){
        long long key;
        cin>>key;
        int index=key%m;
        count[index]++;
    }
    int min=0;
    for(int i=0;i<m;i++){
        if(count[i]>min&&count[i]>0){
           min=count[i];
        }
    }
    if(min>0){
        for(int i=0;i<m;i++){
            if(count[i]==min) cout<<i<<endl;
        }
    }
}