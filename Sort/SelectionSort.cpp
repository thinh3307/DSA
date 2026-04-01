#include<iostream>
using namespace std;
void Output(int *a, int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}
void SelectionSort(int *a, int n){
    for(int i=0;i<n-1;i++){
        cout<<"i = "<<i<<"\n";
        cout<<"Mang truoc khi swap: ";
        Output(a,n);

        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[min]) min=j;
        }
        cout<<"Phan tu lon nhat trong doan ["<<i+1<<", "<<n-1<<"]: "<<a[min]<<"\n";
        cout<<"Swap "<<a[i]<<" va "<<a[min]<<"\n";
        swap(a[i],a[min]);
        cout<<"Mang sau khi swap: ";
        Output(a,n);
        cout<<"\n";
    }
}
int main(){
    int n;
    cin>>n;
    int *A=new int [n];
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<"Mang truoc khi sap xep: "<<"\n";
    Output(A,n);
    cout<<"\nSap xep: "<<"\n";
    SelectionSort(A,n);
    cout<<"Mang sau khi sap xep: \n";
    Output(A,n);

}