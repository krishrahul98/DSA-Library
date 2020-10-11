#include<iostream>
using namespace std;

template <typename T>
class Node {

    private:

        Node<T>* left;
        Node<T>* right;
        T value;

    public:

        Node(T value) {
            this->left = this->right = NULL;
            this->value = value;
        }
        
        void setLeft(Node<T>* left) {
            this->left = left;
        }

        void setRight(Node<T>* right) {
            this->right = right;
        }

        Node<T>* getLeft() {
            return this->left;
        }

        Node<T>* getRight() {
            return this->right;
        }

        T getValue() {
            return this->value;
        }
};

template <typename T>
class BST {

    private:
        Node<T>* root;

        Node<T>* insert(Node<T>* root, int value) {
            if (root == NULL) {
                return new Node<T>(value);
            }
            if (root->getValue() > value) {
                root->setLeft(insert(root->getLeft(), value));
            } else {
                root->setRight(insert(root->getRight(), value));
            }
            return root;
        }

        void inOrder(Node<T>* root) {
            if (root != NULL) {
                inOrder(root->getLeft());
                cout << root->getValue() << " ";
                inOrder(root->getRight());
            }
        }

        void preOrder(Node<T>* root) {
            if (root != NULL) {
                cout << root->getValue() << " ";
                preOrder(root->getLeft());
                preOrder(root->getRight());
            }
        }

        void postOrder(Node<T>* root) {
            if (root != NULL) {
                postOrder(root->getLeft());
                postOrder(root->getRight());
                cout << root->getValue() << " ";
            }
        }

    public:

        BST() {
            this->root = NULL;
        }

        void insert(T value) {
            root = insert(root, value);
        }

        void inOrder() {
            inOrder(root);
            cout << "\n";
        }

        void preOrder() {
            preOrder(root);
            cout << "\n";
        }

        void postOrder() {
            postOrder(root);
            cout << "\n";
        }
};

int main() {
    BST<int> bst;
    cout << "Initialising the tree...\n";
    bst.insert(5);
    bst.insert(15);
    bst.insert(2);
    bst.insert(65);
    bst.insert(100);
    bst.insert(12);
    cout << "Inorder traversal is: ";
    bst.inOrder();
    cout << "Preorder traversal is: ";
    bst.preOrder();
    cout << "Postorder traversal is: ";
    bst.postOrder();
}