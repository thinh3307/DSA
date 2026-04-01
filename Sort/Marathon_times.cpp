#include<iostream>
using namespace std;
void Output(int *A, int n){
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<"\n";
}
void Merge(int *A, int *B, int *C, int sizeB, int sizeC, int runSize){
    int writePos=0;
    int startB=0, startC=0;
    int offsetB=0, offsetC=0;
    int currentB=min(runSize,sizeB);
    int currentC=min(runSize,sizeC);
    while(sizeB>0&&sizeC>0){
        if(B[startB+offsetB]<=C[startC+offsetC]){
            A[writePos++]=B[startB+offsetB];
            offsetB++;
            if(offsetB==currentB){
                for(;offsetC<currentC;offsetC++){
                    A[writePos++]=C[startC+offsetC];
                }
                startB+=currentB; startC+=currentC;
                sizeB-=currentB; sizeC-=currentC;
                offsetB=0; offsetC=0;

                currentB=min(runSize,sizeB);
                currentC=min(runSize,sizeC);
            }
        }
        else{
            A[writePos++]=C[startC+offsetC];
            offsetC++;
            if(offsetC==currentC){
                for(;offsetB<currentB;offsetB++)
                    A[writePos++]=B[startB+offsetB];

                    startB+=currentB; startC+=currentC;
                    sizeB-=currentB; sizeC-=currentC;
                    offsetB=0; offsetC=0;

                    currentB=min(runSize,sizeB);
                    currentC=min(runSize,sizeC);
                
            }
        }
    }
}
void MergerSort(int *A, int n){
    int runSize=1;
    while(runSize<n){
        int readPos=0;
        int writeB=0;
        int writeC=0;
        int *B=new int[n];
        int *C=new int[n];
        while(readPos<n){
            for(int i=0;(readPos<n)&&(i<runSize);i++){
                B[writeB++]=A[readPos++];
            }
            for(int i=0;(readPos<n)&&(i<runSize);i++){
                C[writeC++]=A[readPos++];
            }
        }
        Merge(A,B,C,writeB,writeC,runSize);
        delete[]B;
        delete[]C;
        runSize*=2;
    }
}
int main(){
    int n;
    cin>>n;
    int *A=new int[n];
    for(int i=0;i<n;i++) cin>>A[i];
    MergerSort(A,n);
    Output(A,n);
}