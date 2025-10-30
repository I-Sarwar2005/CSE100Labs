#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node (int k){
        key = k;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* search(Node* s, int k) {
        while(s != nullptr && s->key != k){
            if(k < s->key){
                s = s->left;
            }else{
                s = s->right;
            }
        }
        return s;
    }

    Node* successor(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
    if (node->right != nullptr) {
        Node* curr = node->right;
        while (curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }
    Node* pred = node->parent;
    while (pred != nullptr && node == pred->right) {
        node = pred;
        pred = pred->parent;
    }
    return pred;
}


    void inorder(Node* tree) {
        if (tree != nullptr) {
            inorder(tree->left);
            cout << tree->key << "\n";
            inorder(tree->right);
        }
    }

    void preorder(Node* tree) {
        if (tree != nullptr) {
            cout << tree->key << "\n";
            preorder(tree->left);
            preorder(tree->right);
        }
    }

    void postorder(Node* tree) {
        if (tree != nullptr) {
            postorder(tree->left);
            postorder(tree->right);
            cout << tree->key << "\n";
        }
    }

public:

    BinarySearchTree(){
        root = nullptr;
    }

    void insert(int key) {
        Node* n = new Node(key);
        Node* p = nullptr;
        Node* curr = root;

        while(curr != nullptr){
            p = curr;
            if(n->key < curr->key){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        n->parent = p;
        if(p == nullptr){
            root = n;
        }else{
            if(n->key < p->key){
                p->left = n;
            }else{
                p->right = n;
            }
        }
    }

    void remove(int k) {
        Node* r = search(root, k);
        if (r == nullptr){
            return;
        }

        if(r->left == nullptr && r->right == nullptr){
            if(r == root){
                root = nullptr;
            }else{
                if(r == r->parent->left){
                    r->parent->left = nullptr;
                }else{
                    r->parent->right = nullptr;
                }
            }
            delete r;
            return;
        }
        if (r->left == nullptr || r->right == nullptr){
            Node* child;
            if (r->left != nullptr){
                child = r->left;
            }else{
                child = r->right;
            }

            if(r == root){
                root = child;
                if(child != nullptr){
                    child->parent = nullptr;
                }
            }else{
                if(r == r->parent->left){
                    r->parent->left = child;
                }else{
                    r->parent->right = child;
                    if(child != nullptr){
                        child->parent = r->parent;
                    }
                }
            }
            delete r;
            return;
        }
        Node* succ = successor(r);
        r->key = succ->key;

        Node* succChild = nullptr;
        if (succ->right != nullptr){
            succChild = succ->right;
        }else{
            succChild = nullptr;
        }
        if (succ == root) {
            if (succChild != nullptr){
                 succChild->parent = nullptr;
            }
        } else {
            if (succ == succ->parent->left){
                succ->parent->left = succChild;
            }else
                succ->parent->right = succChild;
            if (succChild != nullptr){
                succChild->parent = succ->parent;
            }
        }

        delete succ;        
    }

    void outputInorder() { 
        inorder(root); 
    }
    void outputPreorder() { 
        preorder(root); 
    }
    void outputPostorder() { 
        postorder(root); 
    }
};

int main() {
    BinarySearchTree tree;
    string input;

    while (cin >> input) {
        if (input == "e") {
            break;
        }else if (input[0] == 'i' && input.size() > 1) {
            int key = stoi(input.substr(1));
            tree.insert(key);
        } else if (input[0] == 'd' && input.size() > 1) {
            int key = stoi(input.substr(1));
            tree.remove(key);
        } else if (input == "oin") {
            tree.outputInorder();
        } else if (input == "opre") {
            tree.outputPreorder();
        } else if (input == "opost") {
            tree.outputPostorder();
        }
    }
    return 0;
}
