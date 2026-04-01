#include<iostream>
#include<vector>
using namespace std;

struct Student{
    int index;
    int GPA;
};
void Output(vector<Student>& arr, int n){
    for(int i=0;i<n;i++) cout<<arr[i].index<<" ";
}
void Merge(vector<Student>&arr,vector<Student>&temp,int left, int mid,int right){
    int i=left;
    int k=left;
    int j=mid+1;
    while(i<=mid && j<=right){
        if(arr[i].GPA<=arr[j].GPA) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=right) temp[k++]=arr[j++];
    for(int p=left;p<=right;p++) arr[p]=temp[p];
}
void MergerSort(vector<Student>& arr, vector<Student>& temp,int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        MergerSort(arr,temp,left,mid);
        MergerSort(arr,temp,mid+1,right);
        Merge(arr,temp,left,mid,right);
    }
}
int main(){
    int n;
    cin>>n;
    vector<Student> arr(n);
    vector<Student> temp(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].GPA;
        arr[i].index=i;
    }
    MergerSort(arr,temp,0,n-1);
    Output(arr,n);

}