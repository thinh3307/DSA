#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *pNext;
    ListNode():val(0), pNext(nullptr){};
    ListNode(int x): val(x), pNext(nullptr){};
    ListNode(int x, ListNode *next):val(x),pNext(next){};

};
class Solution{
    public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *pHead=new ListNode(0);
        ListNode *curr=pHead;
        int carry=0;
        while(l1!=nullptr||l2!=nullptr||carry!=0){
            int x=(l1!=nullptr)?l1->val:0;
            int y=(l2!=nullptr)?l2->val:0;
            int sum=x+y+carry;
            carry=sum/10;
            curr->pNext=new ListNode(sum%10);
            curr=curr->pNext;
            if(l1!=nullptr) l1=l1->pNext;
            if(l2!=nullptr) l2=l2->pNext;
        }
        return pHead->pNext;
    }
};
ListNode *createLinkList(vector<int> arr){
    ListNode*pHead= new ListNode(0);
    ListNode*curr=pHead;
    for(auto n:arr){
        curr->pNext=new ListNode(n);
        curr=curr->pNext;
    }
    return pHead->pNext;
}
void printList(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<(head->pNext?"->":",");
        head=head->pNext;
    }
    cout<<endl;
}
int main(){
    Solution solution;
    ListNode*l1=createLinkList({2,4,3});
    ListNode*l2=createLinkList({5,6,4});
    ListNode*result=solution.addTwoNumbers(l1,l2);
    printList(result);
}