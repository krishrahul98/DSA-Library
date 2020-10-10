public class Binary_Tree_Traversal_Recursive {

	static class Node {
		int data;
		int depth;
		Node left, right;

		Node(int data) {
			this.data = data;
		}
	}

	public Node insert(Node root, int value) {
		if (root == null) {
			return new Node(value);

		}
		if (root.data > value) {
			root.left = insert(root.left, value);
		} else {
			root.right = insert(root.right, value);
		}
		return root;
	}

//PreOrder Traversals	
	public void PreOrder(Node root) {
		if (root == null)
			return;
		System.out.print(root.data + " ");
		PreOrder(root.left);
		PreOrder(root.right);

	}

//InOrder Traversal
	public void InOrder(Node root) {
		if (root == null)
			return;

		InOrder(root.left);
		System.out.print(root.data + " ");
		InOrder(root.right);
	}

//PostOrder Traversal
	public void PostOrder(Node root) {
		if (root == null)
			return;

		PostOrder(root.left);
		PostOrder(root.right);
		System.out.print(root.data + " ");
	}

//Driver Code	
	public static void main(String[] args) {
		Binary_Tree_Traversal_Recursive binarytree= new Binary_Tree_Traversal_Recursive();
		Node root = NULL;
		  root = binarytree.insert(root, 8);
		  root = binarytree.insert(root, 3);
		  root = binarytree.insert(root, 1);
		  root = binarytree.insert(root, 6);
		  root = binarytree.insert(root, 7);
		  root = binarytree.insert(root, 10);
		  root = binarytree.insert(root, 14);
		  root = binarytree.insert(root, 4);
		  
		  System.out.println("Inorder traversal: ");
		  inorder(root);
		  System.out.println("Postorder traversal: ");
		  Postorder(root);
		  System.out.println("Preorder traversal: ");
		  Preorder(root);
		
	}
}