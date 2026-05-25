#include <iostream>
#include <string>

using namespace std;

struct NODE {
    long long info;
    NODE* pNext;
};

struct LIST {
    NODE* pHead;
};

void CreateEmptyList(LIST& l) {
    l.pHead = NULL;
}

void Push(LIST& l, long long x) {
    NODE* p = new NODE{x, l.pHead};
    l.pHead = p;
}

void Pop(LIST& l) {
    if (l.pHead == NULL) return;
    NODE* p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
}

int main() {
    int n;
    cin >> n;
    LIST l;
    CreateEmptyList(l);

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "C") {
            Pop(l);
        } else if (op == "D") {
            Push(l, l.pHead->info * 2);
        } else if (op == "+") {
            long long v1 = l.pHead->info;
            long long v2 = l.pHead->pNext->info;
            Push(l, v1 + v2);
        } else {

            Push(l, stoll(op));
        }
    }

    long long total = 0;
    NODE* p = l.pHead;
    while (p != NULL) {
        total += p->info;
        p = p->pNext;
    }

    cout << total;

    return 0;
}