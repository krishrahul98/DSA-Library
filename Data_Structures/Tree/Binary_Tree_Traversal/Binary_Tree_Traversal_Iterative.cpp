#include <cstdio>
#include <stack>

typedef struct node node;

struct node {
  int data;
  node *left, *right;
  node(int data) {
    this->data = data;
    left = right = nullptr;
  }
};

void InOrder(node *root) {
  std::stack<node*> S;
  do {
    while (root != nullptr) {
      S.push(root);
      root = root->left;
    }

    if (!S.empty()) {
      root = S.top();
      S.pop();

      printf("%d-", root->data);
      root = root->right;
    }
  } while (!S.empty() || root != nullptr);
  printf("\n");
}

void PreOrder(node *root) {
  std::stack<node*> S;
  do {
    while (root != nullptr) {
      S.push(root);
      printf("%d-", root->data);
      root = root->left;
    }

    if (!S.empty()) {
      root = S.top();
      S.pop();
      root = root->right;
    }
  } while (!S.empty() || root != nullptr);
  printf("\n");
}

void PostOrder(node *root) {
  std::stack<node*> S;
  node *prev = nullptr;
  do {
    while (root != nullptr) {
      S.push(root);
      root = root->left;
    }
    while (root == nullptr && !S.empty()) {
      root = S.top();
      if (root->right == nullptr || root->right == prev) {
        printf("%d-", root->data);
        S.pop();
        prev = root;
        root = nullptr;
      } else
        root = root->right;
    }
  } while (!S.empty());
  printf("\n");
}

int main() {
  node* n= new node(5);
  n->right = new node(10);
  n->left = new node(12);
  n->right->left = new node(4);
  n->right->right = new node(50);
  n->left->right = new node(78);

  InOrder(n);
  PreOrder(n);
  PostOrder(n);

  return 0;
}

