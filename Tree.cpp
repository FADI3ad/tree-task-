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
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};


int main() {
    Node* root = new Node(10);

    root->left  = new Node(5);
    root->right = new Node(15);

    root->left->left  = new Node(2);
    root->left->right = new Node(9);

    root->right->left  = new Node(12);
    root->right->right = new Node(20);

    root->left->left->right = new Node(3);

    root->right->right->left  = new Node(17);
    root->right->right->right = new Node(30);

    root->right->right->right->right = new Node(33);

    cout << "Root = " << root->val << el;


}


//By foda