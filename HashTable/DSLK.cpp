#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


struct Node {
    long long val;
    Node* next;
    Node(long long v): val(v), next(nullptr) {}
};

Node* buildList(const vector<long long> &vals) {
    Node dummy(0);
    Node* tail = &dummy;
    for (long long v : vals) {
        tail->next = new Node(v);
        tail = tail->next;
    }
    return dummy.next;
}


vector<long long> intersectLists(Node* a, Node* b) {
    unordered_set<long long>setA;
    for(Node *p=a;p;p=p->next){
        setA.insert(p->val);
    }
    unordered_set<long long>seen;
    vector<long long> result;
    for(Node *p=b;p;p=p->next){
        if(setA.count(p->val)&&!seen.count(p->val)){
            result.push_back(p->val);
            seen.insert(p->val);
        }
    }
    sort(result.begin(),result.end());
    return result;
}

// Return union (unique, sorted asc) of two linked lists.
vector<long long> unionLists(Node* a, Node* b) {
    unordered_set<long long>seen;
    vector<long long>result;
    for(Node *p=a;p;p=p->next){
        if(seen.insert(p->val).second){
            result.push_back(p->val);
        }
    }
    for(Node *p=b;p;p=p->next){
        if(seen.insert(p->val).second){
            result.push_back(p->val);
        }
    }
    sort(result.begin(),result.end());
    return result;
}

void printVec(const vector<long long> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<long long> aVals(n);
    for (int i = 0; i < n; i++) cin >> aVals[i];

    int m;
    cin >> m;
    vector<long long> bVals(m);
    for (int i = 0; i < m; i++) cin >> bVals[i];

    Node* a = buildList(aVals);
    Node* b = buildList(bVals);

    printVec(intersectLists(a, b));
    printVec(unionLists(a, b));

    return 0;
}
