#include<iostream>
#include<vector>
using namespace std;
int main(){
    int M,n;
    if(!(cin>>M>>n)) return 0;
    vector<int> hastable(M,-1);
    int totalCollision=0;
    for(int i=0;i<n;i++){
        int key;
        cin>>key;
        int h_key=key%M;
        if(hastable[h_key]!=-1){
            int j=1;
            while(j<M){
                totalCollision++;
                int nextPos=(h_key+j)%M;
                if(hastable[nextPos]==-1){
                    hastable[nextPos]=key;
                    break;
                }
                j++;
            }
        }
        else{
            hastable[h_key]=key;
        }
    }
    cout<<totalCollision;
}