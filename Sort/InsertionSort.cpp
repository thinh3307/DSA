#include<iostream>
using namespace std;
void Output(int n,int *a){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n"<<"\n";
}
void InsertionSort(int n, int *a){
    int k,x;
    for(int i=1;i<n;i++){
        cout<<"i = "<<i<<"\n";
        cout<<"Mang truoc khi xu ly: ";
        for(int j=0;j<n;j++) cout<<a[j]<<" ";
        cout<<"\n";
        k=i-1;
        x=a[i];
        cout<<"Phan tu dang xet A["<<i<<"] = "<<x<<"\n";
        while(k>=0&&a[k]>x){
            a[k+1]=a[k];
            k--;
        }
        a[k+1]=x;
        cout<<"Chen "<<x<<" vao vi tri k = "<<k+1<<"\n";
        cout<<"Mang sau khi xu ly: ";
        Output(n,a);

    } 
}
int main(){
    int n;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<"Mang truoc khi sap xep: "<<endl;
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"\n"<<"\n"<<"Sap xep: "<<endl;
    InsertionSort(n,A);
    cout<<"\n"<<"Mang sau khi sap xep la: ";
    Output(n,A);
}