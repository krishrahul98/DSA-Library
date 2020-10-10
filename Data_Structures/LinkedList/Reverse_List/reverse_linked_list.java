/* Java code to reverse a linked list

author: AnkitaM84
*/

package hacktober;

import java.util.Scanner;

class node
{
    public int data;
    node next;
    node(int d)
    {
        data = d;
        next = null;
    }
}

public class reverse_linked_list {

	public static node takeInput(Scanner s)
	{
	    System.out.println("Enter the data for nodes: ");
	    int data = s.nextInt();
	    node head = null;
	    while(data != -1)			// linked list keeps on getting created till user enters -1
	    {
	        node newNode = new node(data);
	        if(head == null)
	        {
	            head = newNode;
	        }
	        else
	        {
	            node temp = head;
	            while(temp.next != null)
	            {
	                temp = temp.next;
	            }
	            temp.next = newNode;
	        }
	        data = s.nextInt();
	    }
	    return head;
	}
	
	public static void printLL(node head)
	{
	    node temp = head;
	    while(temp != null)
	    {
	        System.out.print(temp.data + " ");
	        temp = temp.next;
	    }
	}

	public static void main(String[] args)
	{
	    Scanner s = new Scanner(System.in);
	    node head = takeInput(s);
	    head = reverse(head);
	    System.out.println("revesed linked list: ");
	    printLL(head);
	}
	
	public static node reverse(node head) {
		node prev = null, next = null;
		node curr = head;
		while(curr != null) {
			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

}

