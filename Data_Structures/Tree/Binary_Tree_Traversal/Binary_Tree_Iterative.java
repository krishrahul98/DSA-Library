import java.util.ArrayList;
import java.util.Stack;

public class Binary_Tree_Traversal_Iterative {

    public class BinaryTreeNode{
        public int data;
        public BinaryTreeNode left, right;

        public BinaryTreeNode(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    public ArrayList<Integer> preOrderTraversal(BinaryTreeNode root){
        ArrayList<Integer> result = new ArrayList<>();
        // Base Case
        if(root == null)    return result;

        Stack<BinaryTreeNode> BinaryStack = new Stack<>();
        BinaryStack.push(root);

        while(!BinaryStack.isEmpty()){
            BinaryTreeNode temp = BinaryStack.pop();
            result.add(temp.data);

            if(temp.right != null)  BinaryStack.push(temp.right);
            if(temp.left != null) BinaryStack.push(temp.left);
        }
        return result;
    }

    public ArrayList<Integer> InOrderTraversal(BinaryTreeNode root){
        ArrayList<Integer> result = new ArrayList<>();
        Stack<BinaryTreeNode> BinaryStack = new Stack<>();

        BinaryTreeNode currentNode = root;
        boolean done = false;
        while(!done){
            if(currentNode != null){
                BinaryStack.push(currentNode);
                currentNode = currentNode.left;
            }else{
                if(BinaryStack.isEmpty())   done = true;
                else {
                    currentNode = BinaryStack.pop();
                    result.add(currentNode.data);
                    currentNode = currentNode.right;
                }
            }
        }
        return result;
    }

    public ArrayList<Integer> PostrderTraversal(BinaryTreeNode root) {
        ArrayList<Integer> result = new ArrayList<>();

        if (root == null) return result;

        Stack<BinaryTreeNode> BinaryStack = new Stack<>();
        BinaryStack.push(root);

        BinaryTreeNode previous = null;
        while (!BinaryStack.isEmpty()) {
            BinaryTreeNode current = BinaryStack.peek();
            if (previous == null || previous.left == current || previous.right == current) {
                // Traverse from top to bottom, and if current has left child or right child,
                // push into the stack, otherwise, pop out.
                if (current.left != null) BinaryStack.push(current.left);
                else if (current.right != null) BinaryStack.push(current.right);
            }
            else if (current.left == previous) {
                if (current.right != null) BinaryStack.push(current.right);
            }
            else {
                result.add(current.data);
                BinaryStack.pop();
            }
            previous = current;
        }
        return result;
    }

    public static void main(String[] args) {
        // Do whatEver With Implemented Functions here.......
    }
}
