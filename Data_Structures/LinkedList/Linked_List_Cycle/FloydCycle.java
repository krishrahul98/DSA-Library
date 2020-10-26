package hacktober;

import java.util.Arrays;
import java.util.List;
import java.util.Random;

/***
 * 
 * @author afflato https://en.wikipedia.org/wiki/Cycle_detection Floyd's
 *         cycle-finding algorithm is a pointer algorithm that uses only two
 *         pointers, which move through the sequence at different speeds. It is
 *         also called the "tortoise and the hare algorithm", alluding to
 *         Aesop's fable of The Tortoise and the Hare.
 *
 */

public class FloydCycle {

	public static void main(String[] args) {
		List<Integer> initialIntegers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

		// Generate a linked list that may contain a loop with element 100
		LinkedList list = generateList(initialIntegers);

		// list.printList();

		// Test if loop existed or not
		System.out.println("\nLoop existed-->" + list.ifLoopExists());

	}

	public static LinkedList generateList(List<Integer> initialIntegers) {
		LinkedList list = new LinkedList();
		// Randomly add the following node
		// If this node is added to the linked list created then it will generate a link
		LinkedList.Node loopNode = new LinkedList.Node(100);
		int i = 1;

		Random rd = new Random(); // creating Random boolean
		boolean createLoop = rd.nextBoolean();

		for (Integer data : initialIntegers) {
			list.addToTheLast(new LinkedList.Node(data));
			System.out.print(data + " - ");
			i++;
			if (i == 5 && createLoop) {
				list.addToTheLast(loopNode);
				System.out.print(loopNode.value + " - ");
			}
		}

		if (createLoop) {
			list.addToTheLast(loopNode);
			System.out.print(loopNode.value + " - ");
		}

		return list;
	}

	private static class LinkedList {

		private Node head;

		private static class Node {
			private int value;
			private Node next;

			Node(int value) {
				this.value = value;

			}
		}

		public void addToTheLast(Node node) {

			if (head == null) {
				head = node;
			} else {
				Node temp = head;
				while (temp.next != null)
					temp = temp.next;

				temp.next = node;
			}
		}

		public void printList() {
			Node temp = head;
			while (temp != null) {
				System.out.format("%d ", temp.value);
				temp = temp.next;
			}
			System.out.println();
		}

		public boolean ifLoopExists() {
			Node fastPtr = head;
			Node slowPtr = head;
			while (fastPtr != null && fastPtr.next != null) {
				fastPtr = fastPtr.next.next;
				slowPtr = slowPtr.next;
				if (slowPtr == fastPtr)
					return true;

			}
			return false;
		}

	}

}
