#include<iostream>
using namespace std;
struct Employee{
    int salary;
    int index;
};
void Output(Employee *A, int n){
    for(int i=0;i<n;i++) cout<<A[i].index<<" ";
    cout<<"\n";
}
void InsertionSort(Employee *A, int n){
    int k;
    Employee x;
    for(int i=1;i<n;i++){
        k=i-1;
        x=A[i];
        while(k>=0&&A[k].salary>x.salary){
            A[k+1]=A[k];
            k--;
        }
        A[k+1]=x;
    }
}
int main(){
    int n;
    cin>>n;
    Employee *A= new Employee[n];
    for(int i=0;i<n;i++){
        cin>>A[i].salary;
        A[i].index=i;
    }
    InsertionSort(A,n);
    Output(A,n);

}