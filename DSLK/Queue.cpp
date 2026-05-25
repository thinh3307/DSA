#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    vector<int>stack_in;
    vector<int>stack_out;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int x;
            cin>>x;
            stack_in.push_back(x);
        }
        else{
            if(stack_out.empty()){
                while(!stack_in.empty()){
                    stack_out.push_back(stack_in.back());
                    stack_in.pop_back();
                }

            }
        }
        if(type==2){
            if(!stack_out.empty()){
                stack_out.pop_back();
            }
        }
        else if(type==3){
            if(!stack_out.empty()){
                cout<<stack_out.back()<<"\n";
            }
        }
    } 
}
