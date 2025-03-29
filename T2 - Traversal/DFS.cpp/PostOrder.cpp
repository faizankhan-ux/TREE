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

void PostOrder(node* root){
     if(root == NULL) return;

     PostOrder(root->left);
     cout<<root->val<<' ';
     PostOrder(root->right);
}

int main(){
    node* tree = new node(1);
    tree->left = new node(2);
    tree->right = new node(3);
    tree->left->left = new node(4);
    tree->left->right = new node(5);

    cout<<"Depth first search : Postrder traversal (left --> right --> root)\n";
    PostOrder(tree);

    return 0;
}