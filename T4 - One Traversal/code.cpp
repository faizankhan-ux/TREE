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

void OneTraversal(node* root,vector<int> &preorder,vector<int> &inorder, vector<int> &postorder){

     stack<pair<node* , int>> st;
     st.push({root , 1});

     while(!st.empty()){
          auto curr = st.top();
          st.pop();

          if(curr.second == 1){
               preorder.push_back(curr.first->val);
               curr.second++;
               st.push(curr);

               if(curr.first->left){
                    st.push({curr.first->left , 1});
               }
          }
          else if(curr.second == 2){
               inorder.push_back(curr.first->val);
               curr.second++;
               st.push(curr);

               if(curr.first->right){
                    st.push({curr.first->right , 1});
               }
          }
          else{
               postorder.push_back(curr.first->val);
          }
     }


}


int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    idx = 0; 
    node* root = BuildTree(arr);

    vector<int> pre,in,post;
    OneTraversal(root,pre,in,post);

    for(int i : pre) cout<<i<<' ';
    cout<<'\n';

    for(int i : in) cout<<i<<' ';
    cout<<'\n';

    for(int i : post) cout<<i<<' ';
    cout<<'\n';


    //Display(root);
    return 0;
}