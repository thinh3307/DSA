

#include <iostream>
#include <vector>
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

// Fill `out` with values at level `k` from left to right.
void nodesAtLevel(Node* root, int k, vector<int>& out) {
    if(!root) return;
    if(k==0){
        out.push_back(root->data);
        return;
    }
    nodesAtLevel(root->left,k-1,out);
    nodesAtLevel(root->right,k-1,out);
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

    int k;
    cin >> k;

    vector<int> out;
    nodesAtLevel(root, k, out);
    if (out.empty()) {
        cout << "EMPTY" << endl;
    } else {
        for (size_t i = 0; i < out.size(); i++) {
            if (i) cout << " ";
            cout << out[i];
        }
        cout << endl;
    }
    return 0;
}
