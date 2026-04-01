#include<iostream>
using namespace std;
void Output(int *a, int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}
void MergeSort(int *A, int *B, int *C, int sizeB, int sizeC, int temp){
    int currA=0;
    int startB=0, startC=0;
    int offsetB=0, offsetC=0;
    int currB=min(temp,sizeB);
    int currC=min(temp,sizeC);
    while((sizeB>0)&&(sizeC>0)){
        if(B[startB+offsetB]<=C[startC+offsetC]){
            A[currA]=B[startB+offsetB];
            offsetB++;
            if(offsetB==currB){
                for(;offsetC<currC;offsetC++){
                    A[currA]=C[startC+offsetC];
                }
                startB+=currB; sizeB-=currB;
                startC+=currC; sizeC-=currC;
                offsetB=0; offsetC=0;

                currB=min(temp,sizeB);
                currC=min(temp,currC);
            }
        }
        else{
            
        }
    }
}
int main(){
    int n;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++) cin>>A[i];
}