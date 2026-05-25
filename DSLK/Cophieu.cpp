#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
void solve(){
    int n;
    if(!cin>>n)return;
    vector<int>prices(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    stack<int>st;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        while(!st.empty()&&prices[st.top()]<=prices[i]){
            st.pop();
        }
        if(st.empty()){
            v[i]=i+1;
        }
        else{
            v[i]=i-st.top();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<(i==n-1?"":" ");
    }
    cout<<endl;
}
int main(){
    solve();
}
