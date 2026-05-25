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

void LNR(Node* root, bool& first) {
    if (root == NULL) return;
    LNR(root->left, first);
    if (!first) cout << " ";
    cout << root->data;
    first = false;
    LNR(root->right, first);
}

// Returns true if v was found and deleted, false otherwise.
bool deleteNode(Node*& root, int v) {   
    if(!root) return false;
    if(v<root->data) return deleteNode(root->left,v);
    if(v>root->data) return deleteNode(root->right,v);
    if(!root->left&&!root->right){
        delete root;
        root=nullptr;
    }
    else if(!root->left){
        Node *temp=root;
        root=root->right;
        delete temp;
    }
    else if(!root->right){
        Node *temp=root;
        root=root->left;
        delete temp;
    }
    else{
        Node *curr=root->right;
        while(curr->left){
            curr=curr->left;
        }
        root->data=curr->data;
        deleteNode(root->right,curr->data);
    }
    return true;
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

    int v;
    cin >> v;

    if (!deleteNode(root, v)) {
        cout << "NOT_FOUND" << endl;
    } else if (root == NULL) {
        cout << "EMPTY" << endl;
    } else {
        bool first = true;
        LNR(root, first);
        cout << endl;
    }
    return 0;
}
