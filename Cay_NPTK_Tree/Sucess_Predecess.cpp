#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node*& root, Node* node) {
    if (root == NULL) {
        root = node;
        return;
    }

    if (node->data < root->data) {
        if (root->left == NULL) {
            root->left = node;
            return;
        }
        insertNode(root->left, node);
        return;
    }

    if (root->right == NULL) {
        root->right = node;
        return;
    }
    insertNode(root->right, node);
}

// out_found = true and out_val = value if exists; out_found = false otherwise.
void predecessor(Node* root, int x, bool& out_found, int& out_val) {
    out_found=false;
    Node *curr=root;
    while(curr){
        if(curr->data<x){
            out_found=true;
            out_val=curr->data;
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
}

void successor(Node* root, int x, bool& out_found, int& out_val) {
    out_found=false;
    Node *curr=root;
    while(curr){
        if(curr->data>x){
            out_found=true;
            out_val=curr->data;
            curr=curr->left;
        }
        else {
            curr=curr->right;
        }
    }
}

int main() {
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, createNode(data));
    }

    int x;
    cin >> x;

    bool pf, sf;
    int pv, sv;
    predecessor(root, x, pf, pv);
    successor(root, x, sf, sv);

    cout << "Pred: ";
    if (pf) cout << pv; else cout << "NONE";
    cout << "\nSucc: ";
    if (sf) cout << sv; else cout << "NONE";
    cout << "\n";
    return 0;
}
