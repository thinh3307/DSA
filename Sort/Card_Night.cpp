#include<iostream>
using namespace std;
void Output(int *A, int n){
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"\n";
}
void InsertionSort(int *A, int n, int &dem){
    int k,x;
    for(int i=1;i<n;i++){
        k=i-1;
        x=A[i];
        while(k>=0&&A[k]>x){
            A[k+1]=A[k];
            k--;
            dem++;
        }
        A[k+1]=x;
        
    }
}
int main(){
    int n,dem=0;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++) cin>>A[i];
    InsertionSort(A,n,dem);
   
        Output(A,n);
        cout<<dem;
    


}