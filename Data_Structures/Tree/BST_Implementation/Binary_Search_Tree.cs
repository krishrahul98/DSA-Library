/* 

 Example Output:

Randomly generating 10 values.
Values: 28, 41, 32, 46, 41, 14, 12, 22, 11, 20

Inserting values into the tree...


Current Tree:

                       28
            ┌───────────┴───────────┐
           14                      41
      ┌─────┴─────┐           ┌─────┴─────┐
     12          22          32          46
   ┌──┘        ┌──┘
  11          20

Deleting 41 (randomly selected) from the tree.


Current Tree:

                       28
            ┌───────────┴───────────┐
           14                      46
      ┌─────┴─────┐           ┌─────┘
     12          22          32
   ┌──┘        ┌──┘
  11          20

 */

using System;
using System.Collections.Generic;

namespace BST
{
    public class Node
    {
        public int value;
        public Node left;
        public Node right;

        // not required, but it helps provide better display 
        // during debugging. 
        public override string ToString()
        {
            return value.ToString();
        }
    }

    public class BinarySearchTree
    {
        public Node root;

        /// <summary>
        /// Inserts a new node with value specified by <paramref name="val"/>
        /// </summary>
        /// <param name="val">Integer value to insert into the tree.</param>
        public void InsertNode(int val)
        {
            root = InsertNode(root, val);
        }

        /// <summary>
        /// Recursive function to insert a new node in the appropriate location
        /// below the node specified by <paramref name="node"/>. 
        /// </summary>
        /// <param name="node">starting node</param>
        /// <param name="val">new node value</param>
        /// <returns></returns>
        Node InsertNode(Node node, int val)
        {
            // if node is null, create a new node with the 
            // provided value and return it. 
            if (node == null)
            {
                return new Node { value = val };
            }
            // if the new value is less than current node's value
            // insert the value into the right child of current node.
            else if (val < node.value)
            {
                node.left = InsertNode(node.left, val);
            }

            // if the new value is greater than current node's value
            // inser the value into left child of the current node.
            else if (val > node.value)
            {
                node.right = InsertNode(node.right, val);
            }

            return node;
        }

        /// <summary>
        /// Deletes a node which contains the value specified by <paramref name="val"/>
        /// </summary>
        /// <param name="val"></param>
        public void DeleteNode(int val)
        {
            root = DeleteNode(root, val);
        }

        /// <summary>
        /// Recursive function to delete a node with value of <paramref name="val"/>
        /// starting at or below the node specified by <paramref name="node"/>. 
        /// </summary>
        /// <param name="node">starting node</param>
        /// <param name="val">integer value to delete</param>
        /// <returns></returns>
        public Node DeleteNode(Node node, int val)
        {
            if(node == null) return node;

            if(val < node.value)
            {
                node.left = DeleteNode(node.left, val);
            }
            else if(val > node.value)
            {
                node.right = DeleteNode(node.right, val);
            }
            else if(val == node.value)
            {
                // no child nodes
                if(node.left == null && node.right == null)
                {
                    node = null;
                    return node;
                }
                // no left node, right node only.
                else if(node.left == null)
                {
                    node = node.right;
                }
                // no right node, left node only.
                else if(node.right == null)
                {
                    node = node.left;
                }
                // node has both children.
                else
                {
                    Node leaf = FindLeftLeaf(node.right);
                    node.value = leaf.value;
                    node.right = DeleteNode(node.right, leaf.value);
                }
            }
            return node;
        }

        /// <summary>
        /// Find the left leaf node in a branch. Utility function is
        /// used by <code>DeleteNode</code> function.
        /// </summary>
        /// <param name="node">starting node</param>
        /// <returns>left most leaf node.</returns>
        Node FindLeftLeaf(Node node)
        {
            Node current = node;
            while(current.left != null)
            {
                current = current.left;
            }

            return current;
        }

        /// <summary>
        /// Public function used to invoke Print action for the tree.
        /// </summary>
        public void Print()
        {
            // print the tree starting a 'root' node.
            PrintTree(root);
        }

        /// <summary>
        /// Prints an ASCII reprenstation of current BinaryTree which starts 
        /// at the node specified by <paramref name="node"/>.
        /// 
        ///  Based on: https://gist.github.com/rahulsh1/48dc557c76b3fe5609ae4445d5284210
        /// 
        /// </summary>
        /// <param name="node"></param>
        void PrintTree(Node node)
        {
            List<List<string>> lines = new List<List<string>>();
            List<Node> level = new List<Node>();
            List<Node> next = new List<Node>();

            level.Add(node);

            int nn = 1;
            int widest = 0;
            while(nn !=0)
            {
                List<string> line = new List<string>();
                nn = 0;
                foreach(Node n in level)
                {
                    if(n== null)
                    {
                        line.Add(null);
                        next.Add(null);
                        next.Add(null);
                    }
                    else
                    {
                        string aa = n.value.ToString();
                        line.Add(aa);
                        if(aa.Length > widest) {
                            widest = aa.Length;
                        }
                        next.Add(n.left);
                        next.Add(n.right);
                        if(n.left != null) nn++;
                        if(n.right !=null) nn++;
                    }
                }

                if(widest %2 == 1) widest++;
                lines.Add(line);
                List<Node> temp = level;
                level = next;
                next = temp;
                next.Clear();
            }

            int perpiece = (lines[lines.Count-1]).Count * (widest + 4);
            for(int i=0; i < lines.Count; i++)
            {
                List<string> line = lines[i];
                int hpw = (int) Math.Floor(perpiece / 2f) -1;

                if(i>0)
                {
                    for(int j = 0; j < line.Count; j++)
                    {
                        //split node
                        char c = ' ';

                        if(j%2 ==1)
                        {
                            // need to check bounds
                            if(line[j-1] != null)
                            {
                                c = (line[j] != null) ? '┴' : '┘';
                            }
                            else
                            {
                                if(j < line.Count && line[j] != null) c = '└';
                            }
                        }
                        Console.Write(c);

                        //lines and spaces.
                        if(line[j] == null)
                        {
                            for(int k = 0; k < perpiece -1; k++)
                            {
                                Console.Write(" ");  
                            }
                        }
                        else
                        {
                            for (int k = 0; k < hpw; k++) {
                                Console.Write(j % 2 == 0 ? " " : "─");
                            }

                            Console.Write(j % 2 == 0 ? "┌" : "┐");

                            for (int k = 0; k < hpw; k++) {
                                Console.Write(j % 2 == 0 ? "─" : " ");
                            }
                        }
                    }
                    Console.WriteLine();
                }

                // print line of numbers.
                for(int j =0; j < line.Count; j++)
                {
                    string f = line[j];
                    if(f == null) f = "";

                    int gap1 = (int) Math.Ceiling((perpiece/2f) - (f.Length/2f));
                    int gap2 = (int) Math.Floor((perpiece/2f) - (f.Length/2f));

                    // a number
                    for (int k = 0; k < gap1; k++) {
                        Console.Write(" ");
                    }
                    Console.Write(f);
                    for (int k = 0; k < gap2; k++) {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();

                perpiece /= 2;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var tree = new BinarySearchTree();

            // Generate random values between 10 and 50
            int numvalues = 10;

            Console.WriteLine($"Randomly generating {numvalues} values.");

            int[] values = new int[10];
            Random rand = new Random();
            for (int i = 0; i < values.Length; i++) values[i] = rand.Next(10, 50);
            
            Console.WriteLine($"Values: {string.Join(", ", values)}\r\n");

            Console.WriteLine("Inserting values into the tree...\r\n");
            
            // insert each value into BST
            foreach (int i in values)
            {
                tree.InsertNode(i);
            }
            
            Console.WriteLine("\r\nCurrent Tree:\r\n");

            tree.Print();

            int deleteValue = values[rand.Next(0,numvalues-1)];
            
            Console.WriteLine($"\r\nDeleting {deleteValue} (randomly selected) from the tree.\r\n");

            tree.DeleteNode(deleteValue);
            
            Console.WriteLine("\r\nCurrent Tree:\r\n");
            tree.Print();

            Console.WriteLine();
        }
    }
}
