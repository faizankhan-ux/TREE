#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* left;
    node* right;

    node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }

    node(int val , node* left, node* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

void InOrder(node* root){
     if(root == NULL) return;

     InOrder(root->left);
     cout<<root->val<<' ';
     InOrder(root->right);
}

int main(){
    node* tree = new node(1);
    tree->left = new node(2);
    tree->right = new node(3);
    tree->left->left = new node(4);
    tree->left->right = new node(5);

    cout<<"Depth first search : inorder traversal (left --> root --> right)\n";
    InOrder(tree);

    return 0;
}