#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <unordered_map>

using namespace std;

struct BSTNode {
    long long code;
    string name;
    BSTNode *left, *right;
    BSTNode(long long c, const string &n): code(c), name(n), left(nullptr), right(nullptr) {}

};

class StudentStore {

public:

    // Insert into BST (no rebalance needed).

    void insertBST(long long code, const string &name) {
        BSTNode *node=new BSTNode(code,name);
        if(!root){
            root=node;
            return;
        }   
        BSTNode *curr=root;
        while(true){
            if(code<curr->code){
                if(!curr->left){
                    curr->left=node;
                    return;
                }
                curr=curr->left;
            }
            else{
                if(!curr->right){
                    curr->right=node;
                    return;
                }
                curr=curr->right;
            }
        }
    }

    // Lookup in BST. out_found set true if found; out_name set to the name.

    void findBST(long long code, bool &out_found, string &out_name) const {
        BSTNode *curr=root;
        while(curr){
            if(code==curr->code){
                out_found=true;
                out_name=curr->name;
                return;
            }
            curr=code<curr->code?curr->left:curr->right;
        }
        out_found=false;
    }

    // After all inserts, inorder traverse BST and fill the hashmap.

    void buildHashFromBST() {
        inorder(root);

    }

    // Lookup in hashmap.

    void findHash(long long code, bool &out_found, string &out_name) const {
        auto it=table.find(code);
        if(it==table.end()){
            out_found=false;
            return;
        }
        out_found=true;
        out_name=it->second;


    }

private:
    BSTNode* root = nullptr;
    unordered_map<long long, string> table;
    void inorder(BSTNode* node) {
        if(!node) return;
        inorder(node->left);
        table[node->code]=node->name;
        inorder(node->right);
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    StudentStore store;

    for (int i = 0; i < n; i++) {
        long long code;
        string name;
        cin >> code >> name;
        store.insertBST(code, name);
    }
    store.buildHashFromBST();
    int q;
    cin >> q;
    vector<long long> queries(q);
    for (int i = 0; i < q; i++) cin >> queries[i];
    auto t0 = chrono::high_resolution_clock::now();
    long long bstChecksum = 0;
    for (long long c : queries) {
        bool found; string name;
        store.findBST(c, found, name);
        if (found) bstChecksum += (long long)name.size();
    }
    auto t1 = chrono::high_resolution_clock::now();
    for (long long c : queries) {
        bool found; string name;
        store.findHash(c, found, name);
        cout << (found ? name : string("NOT_FOUND")) << "\n";
    }
    auto t2 = chrono::high_resolution_clock::now();
    cerr << "BST  total: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << " us\n";
    cerr << "Hash total: " << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << " us\n";
    cerr << "BST checksum (sanity): " << bstChecksum << "\n";
    return 0;
}

