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

    stack<node*> st;
    node* curr = root;

    while(st.empty() == false || curr != NULL){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }else{
            node* temp = st.top()->right;

            if(temp == NULL){
                temp = st.top();
                st.pop();
                Ans.push_back(temp->val);

                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    Ans.push_back(temp->val);
                }

            }
            else{
                curr = temp;
            }
        }
    }

    return Ans;

}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    idx = 0; 
    node* root = BuildTree(arr);
     
    vector<int> ans = PostOrder(root);
    for(int i:ans) cout<<i<<' ';

    //Display(root);
    return 0;
}