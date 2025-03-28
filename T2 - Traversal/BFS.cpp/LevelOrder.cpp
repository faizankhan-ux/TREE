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

vector<vector<int>> BFS(node* root){
     vector<vector<int>> Ans;      //Store's Answer
     if(root == NULL) return Ans;

     queue<node*> q;               // stores's level wise values

     q.push(root);                 // pushing first val (head)
     while(!q.empty()){
          int size = q.size();
          vector<int> Level;       // store's particular level

          for(int i = 0; i < size; i++){
               node* currNode = q.front();
               q.pop();

               if(currNode->left) q.push(currNode->left); //insert in queue if it has left or right
               if(currNode->right) q.push(currNode->right);
               Level.push_back(currNode->val);
          }

          Ans.push_back(Level);
     }

     return Ans;
}

int main(){
    node* tree = new node(1);
    tree->left = new node(2);
    tree->right = new node(3);
    tree->left->left = new node(4);
    tree->left->right = new node(5);
    tree->right->left = new node(6);
    tree->right->right = new node(7);

    vector<vector<int>> Ans = BFS(tree);

    for(int i=0; i<Ans.size(); i++){
          for(int j=0; j<Ans[i].size(); j++){
               cout<<Ans[i][j]<<' '; 
          }
          cout<<'\n';
    }

    return 0;
}