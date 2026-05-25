

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

void NLR(Node* root, bool& first) {
    if (root == NULL) return;
    if (!first) cout << " ";
    cout << root->data;
    first = false;
    NLR(root->left, first);
    NLR(root->right, first);
}

// Returns true if v was inserted, false if v already exists.
bool insertUnique(Node*& root, int v) {
    Node *curr=root;
    Node *parent=nullptr;
    while(curr){
        if(v==curr->data) return false;
        parent=curr;
        curr=v<curr->data?curr->left:curr->right;
    }
    Node *node= createNode(v);
    if(!parent){
        root=node;
        return true;
    }
    if(v<parent->data) parent->left=node;
    else parent->right=node;
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

    if (!insertUnique(root, v)) {
        cout << "DUPLICATE" << endl;
    } else {
        bool first = true;
        NLR(root, first);
        cout << endl;
    }
    return 0;
}
