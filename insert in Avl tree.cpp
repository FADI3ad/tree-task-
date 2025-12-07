//
// Created by FODA on 12/7/2025.
//
#include <bits/stdc++.h>
//By foda
using namespace std;
#define ll long long
#define ch char
#define el endl
#define str string
#define cn cin
#define ct cout
#define bl bool
#define el '\n'
#define What_F() ios::sync_with_stdio(0); cin.tie(0);
struct Node {
    int key;
    Node *left, *right;
    int height;

    Node(int k) : key(k), left(NULL), right(NULL), height(1) {

    }
};


int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

void update(Node* n) {
    n->height = 1 + max(height(n->left), height(n->right));
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    update(y);
    update(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    update(x);
    update(y);

    return y;
}


Node* insertNode(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    update(node);

    int bal = getBalance(node);


    if (bal > 1 && key < node->left->key)
        return rightRotate(node);


    if (bal < -1 && key > node->right->key)
        return leftRotate(node);


    if (bal > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }


    if (bal < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


void printTreeASCII(Node* root, string indent = "", bool last = true) {
    if (!root) return;

    cout << indent;

    if (last) {
        cout << "`-- ";
        indent += "    ";
    } else {
        cout << "|-- ";
        indent += "|   ";
    }

    cout << root->key << "\n";

    printTreeASCII(root->left, indent, false);
    printTreeASCII(root->right, indent, true);
}



void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node* cur = q.front();
            q.pop();
            cout << cur->key << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << "\n";
    }
}


int main() {
    Node* root = NULL;

    vector<int> vals = {10,5,15,2,9,12,20,3,17,30};
    for (int x : vals)
        root = insertNode(root, x);


    //insert 33
    root = insertNode(root, 33);
    cout << "\n AVL Tree (ASCII View):\n";
    printTreeASCII(root);
    cout << "\n Level Order View:\n";
    printLevelOrder(root);

    return 0;
}
//By foda