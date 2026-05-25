#include<iostream>
#include<string>
using namespace std;
struct Sinhvien{
    char*MSSV;
    char*Hoten;
    char Gioitinh;
    float diem;
    float drl;
};
struct NODE{
    Sinhvien info;
    NODE *pNext;
};
struct LIST{
    NODE *pHead;
    NODE *pTail;
};
void CreateEmptyList(LIST& l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE* CreateEmptyNode(Sinhvien x){
    NODE *p= new NODE;
    if(p==NULL) exit(1);
    p->info=x;
    p->pNext=NULL;
    return p;
}
void InsertTail(LIST&l, NODE *p){
    if(l.pHead==NULL){
        l.pHead=p;
        l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
Sinhvien Nhap(Sinhvien&sv){
    sv.MSSV = new char[20];
    sv.Hoten = new char[50];
    cin >> sv.MSSV;
    cin.ignore();
    cin.getline(sv.Hoten, 50);
    cin>>sv.Gioitinh;
    cin>>sv.diem;
    cin>>sv.drl;
    cin.ignore();
    return sv;
}
void Xuat(NODE*p){
    cout<<"MSSV: "<<p->info.MSSV<<"\n";
    cout<<"Ho ten: "<<p->info.Hoten<<"\n";
    cout<<"Gioi tinh: "<<p->info.Gioitinh<<"\n";
    cout<<"Diem hoc tap: "<<p->info.diem<<"\n";
    cout<<"Diem ren luyen: "<<p->info.drl<<"\n";
}
void PrintList(LIST l){
    cout<<"--THONG TIN SINH VIEN--\n";
    NODE*p=l.pHead;
    while(p!=NULL){
        Xuat(p);
        p=p->pNext;
    }
}
void checkMSSV(LIST l, char*MSSV){
    NODE*p=l.pHead;
    while(p!=NULL){
        if(p->info.MSSV==MSSV){
            Xuat(p);
            return;
        }
        p=p->pNext;
    }

}
void checkDiem(const LIST& l){
    NODE*p=l.pHead;
    while(p!=NULL){
        if(p->info.diem>=7&&p->info.drl>=70) Xuat(p);
        p=p->pNext;
    }
}
void Nam_Nu(const LIST& l,int& nam, int& nu){
    NODE*p=l.pHead;
    while(p!=NULL){
        if(p->info.Gioitinh='F') nu++;
        else nam++;
    }
}
void Xeploai(const LIST& l){
    NODE*p=l.pHead;
    while(p!=NULL){
        Xuat(p);
        if(p->info.diem<=3.6) cout<<"Xep loai: Yeu\n";
        else if(p->info.diem>=5.0&&p->info.diem<6.5) cout<<"Xep loai: TB\n";
        else if(p->info.diem>=6.5&&p->info.diem<7.0) cout<<"Xep loai: TB kha\n";
        else if(p->info.diem>=7.0&&p->info.diem<8.0) cout<<"Xep loai: Kha\n";
        else if(p->info.diem>=8.0&&p->info.diem<9.0) cout<<"Xep loai: Gioi\n";
        else cout<<"Xep loai: Xuat sac\n";
        p=p->pNext;
    }
}
int main(){
    int n;
    cin>>n;
    LIST l;
    CreateEmptyList(l);
    for(int i=0;i<n;i++){
        Sinhvien sv;
        InsertTail(l,CreateEmptyNode(Nhap(sv)));
    }

}