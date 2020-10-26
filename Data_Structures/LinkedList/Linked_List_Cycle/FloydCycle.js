/* Credits to Joshua Blankenship for a Medium article explaining this concept and algorithm in detail
   https://medium.com/@joshuablankenshipnola/checking-for-linked-list-cycles-in-javascript-77ec9adc6822 */

const floydCycle = (linkedList) => {

  // Create a slow pointer and a fast pointer
  let slowPointer = linkedList;
  let fastPointer = linkedList;

  // While both exist and the faster pointer has a next value
  while(fastPointer && fastPointer.next) {
    // Move the slow pointer by a single node
    slowPointer = slowPointer.next;
    // Move the fast pointer by two nodes
    fastPointer = fastPointer.next.next;

    // If both pointers intersect at any point, then the linked list contains a loop
    if (slowPointer === fastPointer) {
      return true;
    }
  }

  // Return false if no cycle is found
  return false;
}