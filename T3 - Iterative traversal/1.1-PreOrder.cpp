#include<bits/stdc++.h>
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

vector<int> PreOrder(node* root){
     vector<int> Ans;
     if(root == NULL) return Ans;
     stack<node*> st;

     st.push(root);

     while(!st.empty()){
          node* curr = st.top();
          st.pop();
          Ans.push_back(curr->val);

          if(curr->right) st.push(curr->right);
          if(curr->left) st.push(curr->left);

     }
     return Ans;
}

int main(){
    node* tree = new node(1);
    tree->left = new node(2);
    tree->right = new node(3);
    tree->left->left = new node(4);
    tree->left->right = new node(5);

    vector<int> Ans = PreOrder(tree);

    for(auto I : Ans){
      cout<<I<<' ';
    }

    return 0;
}