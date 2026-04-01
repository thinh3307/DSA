#include<iostream>
using namespace std;
void Output(int *A, int n){
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"\n";
}
void SelectionSort(int *A, int n,int &dem){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min]) min=j;
        }
        if (min != i) {
            swap(A[i], A[min]);
            dem++;
        }
    }
}
int main(){
    int n,dem=0;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++) cin>>A[i];
    SelectionSort(A,n,dem);
    Output(A,n);
    cout<<dem;
}