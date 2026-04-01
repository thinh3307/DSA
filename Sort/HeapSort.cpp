#include<iostream>
using namespace std;
void Output(int *a, int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}
void OutputHeapify(int *A, int n, int heapSize){
    for(int i=0;i<n;i++){
        if(i==heapSize) cout<<"| ";
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}
void heapify(int *a, int rootIndex, int heapSize){
    int left=2*rootIndex+1;
    while(left<heapSize){
        int largerChild=left;
        bool rightChildExists=(left+1<heapSize);
        if(rightChildExists&&a[left+1]>a[left]) largerChild=left+1;

        if(a[rootIndex]>=a[largerChild]) return;

        swap(a[rootIndex],a[largerChild]);
        rootIndex=largerChild;
        left=2*rootIndex+1;
        
    }
}
void buildHeap(int *A, int n){
    int lastNode=(n-1)/2;
    for(int i=lastNode;i>=0;i--){
        heapify(A,i,n);
    }
}
void HeapSort(int *A, int n){
    buildHeap(A,n);
    cout<<"Mang sau khi BuildHeap: ";
    Output(A,n);
    int heapSize=n;
    while(heapSize>1){
        cout<<"Swap "<<A[0]<<" va "<<A[heapSize-1]<<"\n\n";
        swap(A[0],A[heapSize-1]);
        heapSize--;
        heapify(A,0,heapSize);
        cout<<"Mang sau khi heapify voi n = "<<heapSize<<": ";
        OutputHeapify(A,n,heapSize);
    }
}
int main(){
    int n;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<"Mang truoc khi sap xep: \n";
    Output(A,n);
    cout<<"\nSap xep:\n";
    HeapSort(A,n);
    cout<<"\nMang sau khi sap xep:\n";
    Output(A,n);
}