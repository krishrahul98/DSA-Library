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

        public LinkedList(ListNode<T> node = null)
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
        /// Rotates linked list by k places. k is assumed to be non-negative
        /// </summary>
        public void rotateLinkedList(int k)
        {
            // Triviality check
            if (this.rootNode == null || this.rootNode.next == null)
            {
                return;
            }

            int n = 1;

            ListNode<T> tail = this.rootNode;

            // Get size of list
            while (tail.next != null)
            {
                n++;
                tail = tail.next;
            }

            k %= n;

            if (k == 0)
            {
                // If k is a multiple of n ==> no effect of rotation
                return;
            }

            ListNode<T> newHead = this.rootNode;
            ListNode<T> newTail = this.rootNode;
            
            // Main logic for rotation
            while (n > k)
            {
                newTail = newHead;
                newHead = newHead.next;
                n--;
            }

            newTail.next = null;
            tail.next = this.rootNode;

            this.rootNode = newHead;
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
            Console.WriteLine("Enter size of list:");
            int n = Convert.ToInt32(Console.ReadLine());

            // Define linked list with no nodes
            var linkedList = new LinkedList<int>();

            Console.WriteLine("Enter list items, one at a time:");

            // Add nodes from the user
            for (int i = 0; i < n; i++)
            {
                var val = Convert.ToInt32(Console.ReadLine());
                linkedList.insertNewNode(val);
            }

            Console.WriteLine("Enter the value of k, the number of places by which to rotate right");
            int k = Convert.ToInt32(Console.ReadLine());

            //Before rotating
            Console.WriteLine("Original list:");
            linkedList.printLinkedList();

            linkedList.rotateLinkedList(k);

            //After rotating
            Console.WriteLine("After rotating:");
            linkedList.printLinkedList();

            Console.ReadKey();
        }
    }
}

/*
 * Input
 *
 * 5
 * 1 2 3 4 5
 *
 * 2
 *
 * Output
 *
 * Original List
 * 1 2 3 4 5
 * Rotating by k = 2
 * 4 5 1 2 3
 */
