using System;

namespace DataStructures
{
    /// <summary>
    /// Custom class for defining nodes in a singly linked list.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    internal class ListNode<T>
    {
        internal T val;
        internal ListNode<T> next;

        public ListNode(T val)
        {
            this.val = val;
            this.next = null;
        }
    }

    /// <summary>
    /// Custom class for defining a singly linked list with a method for reversing it.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    internal class LinkedList<T>
    {
        private ListNode<T> rootNode;

        public LinkedList(ListNode<T> node=null)
        {
            this.rootNode = node;
        }

        /// <summary>
        /// Creates a new node with the user-provided value and appends to the list.
        /// </summary>
        /// <param name="value"></param>
        public void insertNewNode(T value)
        {
            var node = new ListNode<T>(value);
            var head = this.rootNode;

            if (head != null)
            {
                ListNode<T> temp = head;

                while (temp.next != null)
                {
                    temp = temp.next;
                }

                temp.next = node;
            }
            else
            {
                this.rootNode = node;
            }
        }

        /// <summary>
        /// Reverses linked list by iterating over all elements and changing references.
        /// </summary>
        public void reverseLinkedList()
        {
            ListNode<T> curr = this.rootNode, next = null;

            while (curr != null)
            {
                ListNode<T> temp = curr.next;
                curr.next = next;
                next = curr;
                curr = temp;
            }

            this.rootNode = next;
        }

        public void printLinkedList()
        {
            var head = this.rootNode;

            while (head != null)
            {
                Console.Write(head.val + " ");
                head = head.next;
            }

            Console.WriteLine();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            // Define linked list with no nodes
            var linkedList = new LinkedList<int>();

            // Add nodes from the user
            for (int i = 0; i < n; i++)
            {
                var val = Convert.ToInt32(Console.ReadLine());
                linkedList.insertNewNode(val);
            }

            //Before reversing
            Console.WriteLine("Original List");
            linkedList.printLinkedList();

            linkedList.reverseLinkedList();

            //After reversing
            Console.WriteLine("After reversing");
            linkedList.printLinkedList();

            Console.ReadKey();
        }
    }
}

/*
 * Input
 * 5
 * 1 2 3 4 5
 *
 * Output
 * Original List
 * 1 2 3 4 5
 * Reversing
 * 5 4 3 2 1
 */
