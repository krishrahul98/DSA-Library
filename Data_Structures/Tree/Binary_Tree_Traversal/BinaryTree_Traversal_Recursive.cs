// C# program for different tree traversals 
using System;

/* Class containing left and right child of current node and key value*/

class Node {
  public int key;
  public Node left,
  right;
  public Node(int item) {
    key = item;
    left = right = null;
  }
}

class BinaryTree {
  Node root;
  BinaryTree() {
    root = null;
  }
  /* Given a binary tree, print its nodes according to the "bottom-up" postorder traversal. */
  void printPostorder(Node node) {
    if (node == null) return;
    // first recur on left subtree 
    printPostorder(node.left);
    // then recur on right subtree 
    printPostorder(node.right);
    // now deal with the node 
    Console.Write(node.key + " ");
  }
  /* Given a binary tree, print 
its nodes in inorder*/
  void printInorder(Node node) {
    if (node == null) return;
    /* first recur on left child */
    printInorder(node.left);
    /* then print the data of node */
    Console.Write(node.key + " ");
    /* now recur on right child */
    printInorder(node.right);
  }
  /* Given a binary tree, print 
its nodes in preorder*/
  void printPreorder(Node node) {
    if (node == null) return;
    /* first print data of node */
    Console.Write(node.key + " ");
    /* then recur on left sutree */
    printPreorder(node.left);
    /* now recur on right subtree */
    printPreorder(node.right);
  }
  // Wrappers over above recursive functions 
  void printPostorder() {
    printPostorder(root);
  }
  void printInorder() {
    printInorder(root);
  }
  void printPreorder() {
    printPreorder(root);
  }

  // Driver Code 
  static public void Main(String[] args) {
    BinaryTree tree = new BinaryTree();
    tree.root = new Node(1);
    tree.root.left = new Node(2);
    tree.root.right = new Node(3);
    tree.root.left.left = new Node(4);
    tree.root.left.right = new Node(5);
    Console.WriteLine("Preorder traversal " + "of binary tree is ");
    tree.printPreorder();
    Console.WriteLine("\nInorder traversal " + "of binary tree is ");
    tree.printInorder();
    Console.WriteLine("\nPostorder traversal " + "of binary tree is ");
    tree.printPostorder();
  }
}