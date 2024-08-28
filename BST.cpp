#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node* GetNewNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    return newNode;
}
Node* Insert(Node *root,int data){
    if(root == NULL){
        root = GetNewNode(data);
    }else if(data > root->data){
        root->right = Insert(root->right, data);
    }else{
        root->left = Insert(root->left, data);
    }
    return root;
}
bool Search(Node *root, int target){
    if(root == NULL){
        cout << "Not found\n";
        return 0;
    }
    if(root->data == target){
        cout << root->data << " was Found\n";
        return 1;
    }else if(target > root->data){
        return Search(root->right,target);
    }else{
        return Search(root->left,target);
    }
}
int find_max(Node *root){
    if(root == NULL) {
        cout << "Tree is empty\n";
        return NULL;
    };
    if(root->right == NULL){
        return root->data;
    }
    return find_max(root->right);
}
int find_min(Node *root){
    if(root == NULL) {
        cout << "Tree is empty\n";
        return NULL;
    };
    if(root->left == NULL){
        return root->data;
    }
    return find_min(root->left);
}
//============================traversal
void BFS(Node *root){
    // TC = O(n) for all cases
    /*
        SC = O(n) average, it depends on what will be stored in the queue also
        ,so it depends on the shape of the tree
    */
    if(root == NULL) return;

    queue<Node*> Q;
    Q.push(root);
    // if Q not empty
    while(!Q.empty()){
        Node* current = Q.front();
        cout << current->data << endl;
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}
// DFS
// TC = O(n)
/* SC
    worest case : O(h) "h is the hight of the tree"
    Best/ average: o(log(n))
 */
void Preorder(Node *root){
    // if empty || reached the end
    if(root == NULL) return;
    cout << root->data << endl;
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node *root){
    // if empty || reached the end
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
void Postorder(Node *root){
    // if empty || reached the end
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << endl;
}


int32_t main() {
    Node *root = NULL;
    root = Insert(root , 15);
    Insert(root , 10);
    Insert(root , 8);
    Insert(root , 20);
    Insert(root , 9);
    Insert(root , 13);
    Insert(root , 16);
    Insert(root , 25);
//    cout << find_max(root) << endl;
//    cout << find_min(root) << endl;
//  =============================================
//    BFS(root);
//    Preorder(root);
//    Inorder(root);
//    Postorder(root);
}