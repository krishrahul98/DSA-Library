class Node{
    private int data;
    private Node left;
    private Node right;

    public Node(int element){
        data = element;
        left = null;
        right = null;
    }

    public void setRightChild(Node n)
    {
        right = n;
    }

    public void setLeftChild(Node n){
        left = n;
    }

    public Node getRightChild(){
        return right;
    }

    public Node getLeftChild(){
        return left;
    }

    public int getData(){
        return data;
    }

    public void setData(int x){
        data = x;
    }
}

class Main{

    // mathod to search for an element in a tree
    public static Node search(int x, Node n){
        if (n==null || n.getData()==x) 
            return n;
        else if(n.getData()>x)
            return search(x, n.getLeftChild()); 
        else 
            return search(x, n.getRightChild());
    }

    //method to find the minimum value in a tree
    public static Node findMinimum(Node root){
        if(root==null)
            return null;
        else if(root.getLeftChild() != null)
            return findMinimum(root.getLeftChild());
        return root;
    }
    
    // method to insert a new node
    public static Node insert(Node root, int x){
        if (root == null)
            return new Node(x);
        else if(x>root.getData())
            root.setRightChild(insert(root.getRightChild(),x));
        else
            root.setLeftChild(insert(root.getLeftChild(),x));
        return root;
    }

    // method to delete a node
    public static Node delete(Node root, int x){
        //searching for the item to be deleted
        if(root==null)
            return null;
        if (x>root.getData())
            root.setRightChild(delete(root.getRightChild(), x));
        else if(x<root.getData())
            root.setLeftChild(delete(root.getLeftChild(), x));
        else
        {
            //No Children
            if(root.getLeftChild()==null && root.getRightChild()==null)
            {
                root = null;
                return null;
            }

            //One Child
            else if(root.getLeftChild()==null || root.getRightChild()==null)
            {
                Node temp;
                if(root.getLeftChild()==null)
                    temp = root.getRightChild();
                else
                    temp = root.getLeftChild();
                root = null;
                return temp;
            }

            //Two Child
            else
            {
                Node temp = findMinimum(root.getRightChild());
                root.setData(temp.getData());
                root.setRightChild(delete(root.getRightChild(), temp.getData()));
            }
        }
        return root;
    }

    //method for inorder
    public static void inorder(Node root){
        if(root!=null){
            inorder(root.getLeftChild()); 
            System.out.print(" "+root.getData()+" ");
            inorder(root.getRightChild());
        }
    }

    /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */

    public static void main(String[] args){
        Node root;
        root = new Node(20);
        insert(root,5);
        insert(root,1);
        insert(root,15);
        insert(root,9);
        insert(root,7);
        insert(root,12);
        insert(root,30);
        insert(root,25);
        insert(root,40);
        insert(root, 45);
        insert(root, 42);

        inorder(root);
        System.out.println("");

        root = delete(root, 1);
        root = delete(root, 40);
        root = delete(root, 45);
        root = delete(root, 9);
        inorder(root);
        
        System.out.println("");
    }
}
