#include<iostream>
using namespace std;
struct Battery{
    int index;
    int number;
};
void Output(Battery *A, int n){
    for(int i=0;i<n;i++) cout<<A[i].index<<" ";
    cout<<"\n";
}
void SelectionSort(Battery *A, int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(A[j].number<A[min].number) min=j;
        }
        swap(A[i],A[min]);
    }
}

int main(){
    int n;
    cin>>n;
    Battery *A=new Battery[n];
    for(int i=0;i<n;i++){
        cin>>A[i].number;
        A[i].index=i;
    }
    SelectionSort(A,n);
    Output(A,n);
}