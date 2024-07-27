#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int item): data(item), left(nullptr), right(nullptr){}
};
class Main{
public:
    Node* root;
    Main() : root(nullptr) {}
    int minDepth(){
        return minDepth(root);
    }
private:
    int minDepth(Node*root){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root -> right == nullptr) return 1;
        if(root ->left == nullptr) return minDepth(root->right) +1;
        if(root->right == nullptr) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
public:
    void buildtree(vector<string>& nodes){
        if(nodes.empty()) return;
        root = new Node(stoi(nodes[0]));
        queue<Node*> q;
        q.push(root);
        size_t i = 1;  //kieu du lieu khong dau
        while(!q.empty() && i < nodes.size()){
            Node* cur = q.front();
            q.pop();

            if(i < nodes.size() && nodes[i] != "null"){
                cur->left = new Node(stoi(nodes[i]));
                q.push(cur->left);
            }
            i++;
            if(i < nodes.size() && nodes[i] != "null"){
                cur->right = new Node(stoi(nodes[i]));
                q.push(cur->right);
            }
            i++;
        }
    }
};

//Tach chuoi dau vao thanh cac phan tu
vector<string> inputArray(){
    string text;
    getline(cin, text);
    stringstream ss(text);
    string item;
    vector<string>res;
    while(ss >> item) res.push_back(item);
    return res;
}
int main (){
    Main tree;
    vector<string> tmp = inputArray();
    tree.buildtree(tmp);
    cout << tree.minDepth() << endl;
    return 0;
}
