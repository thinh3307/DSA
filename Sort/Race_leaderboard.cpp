#include<iostream>
using namespace std;
void Output(int *A, int n){
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"\n";
}
void Quicksort(int *A, int left, int right, int n){
    if(left>=right) return;
    int pivot=A[(left+right)/2];
    int i=left,  j=right;
    while(i<=j){
        while(A[i]<pivot) i++;
        while(A[j]>pivot)j--;
        if(i<=j){
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    Quicksort(A,left,j,n);
    Quicksort(A,i,right,n);
}
int main(){
    int n;
    cin>>n;
    int *A=new int [n];
    for(int i=0;i<n;i++) cin>>A[i];
    Quicksort(A,0,n-1,n);
    Output(A,n);
}