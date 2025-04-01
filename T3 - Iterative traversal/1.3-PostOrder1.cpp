#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class node {
public:
    int val;
    node* left;
    node* right;

    node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    node(int val, node* left, node* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int idx = 0;
node* BuildTree(vector<int>& arr) {
    if (idx >= arr.size() || arr[idx] == -1) return nullptr;

    node* newNode = new node(arr[idx]);
    idx++;
    newNode->left = BuildTree(arr);
    idx++;
    newNode->right = BuildTree(arr);
    return newNode;
}

void Display(node* root) {
    if (!root) return;

    queue<node*> q;
    q.push(root);


    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();

            cout << curr->val << ' ';
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << '\n';
    }
}


vector<int> PostOrder(node* root){
     vector<int> Ans;
     if(!root) return Ans;

     stack<node*> st1;
     stack<node*> st2;

     st1.push(root);

     while(!st1.empty()){  //runs till first stack become empty
          node* curr = st1.top(); // get the st1.top()
          st1.pop(); //pop it

          st2.push(curr); // push it in st2

          if(curr->left) st1.push(curr->left); // push left and right to st1 if exists
          if(curr->right) st1.push(curr->right);
     }

     while(!st2.empty()){  // Print all eement from st2 (Post Order travesal)
          Ans.push_back(st2.top()->val);
          st2.pop();
     }
     return Ans;
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    
    idx = 0; // Reset idx before building the tree
    node* root = BuildTree(arr);

     vector<int> ans = PostOrder(root);

     for(int i : ans) cout<<i<<' ';
     //Display(root);
    return 0;
}