#include<iostream>
using namespace std;
void Output(int *A, int n){
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"\n";
}
void QuickSort(int *A, int left, int right,int n){
    if(left>=right) return;
    cout<<"Truoc: ";
    Output(A,n);

    int pivot=A[(left+right)/2];
    int i=left, j=right;
    cout<<"Left="<<left<<" - "<<"Right="<<right<<" - "<<"Pivot="<<pivot<<"\n";
    while(i<=j){
        while(A[i]<pivot) i++;
        while(A[j]>pivot) j--;
        if(i<=j){
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    cout<<"Sau: ";
    Output(A,n);
    if (left < j || i < right) cout << "\n";
    QuickSort(A,left,j,n);
    QuickSort(A,i,right,n);
   

}
int main(){
    int n;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<"Mang truoc khi sap xep:\n";
    Output(A,n);
    cout<<"\nSap xep:\n";
    QuickSort(A,0,n-1,n);
    cout<<"\nMang sau khi sap xep:\n";
    Output(A,n);
}