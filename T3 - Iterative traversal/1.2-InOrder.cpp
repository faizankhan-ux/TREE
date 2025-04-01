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

    cout << "Tree:\n";
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

vector<int> InOrder(node* root){
     vector<int> Ans;
     if(!root) return Ans;

     stack<node*> st;
     node* var = root;

     while(true){
          if(var != NULL){
               st.push(var);
               var = var->left;
          }
          else{
               if(st.empty()) break;

               var = st.top();
               st.pop();

               Ans.push_back(var->val);
               var = var->right;
          }
     }
     return Ans;
}

int main(){
     vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
     node* root = BuildTree(arr);
     
     vector<int> Ans = InOrder(root);


     Display(root);

     for(int i=0; i<arr.size(); i++) cout<<arr[i]<<' ';

     return 0;
}