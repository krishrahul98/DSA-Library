/// Merge two sorted linked lists and return it as a new sorted list. The new list should be made
/// by splicing together the nodes of the first two lists.
///
/// ## Example
/// `Input: 1->2->4, 1->3->4`
/// `Output: 1->1->2->3->4->4`
///

// Definition for singly-linked list.
function ListNode(val, next) {
  this.val = (val===undefined ? 0 : val)
  this.next = (next===undefined ? null : next)
}

// helper function to create a list of n nodes
function createList(n) {
  let head = new ListNode(n);
  for (let i=n-1; i > 0; i--) {
    head = new ListNode(i, head);
  }
  return head;
}

// pushes a value onto the end of the list
function push(head, val) {
  let node = new ListNode(val);
  while (head !== null) {
    if (head.next === null) {
      head.next = node;
      return;
    } else {
      head = head.next;
    }
  }
}

// prints each node of the list
function printList(head) {
  let node = head;
  while (node != null) {
    console.log(node.val);
    node = node.next;
  }
}

// merge two sorted lists, returning a new list
function mergeLists(l1, l2) {
  let merged = new ListNode();

  while (l1 !== null || l2 !== null) {
    if (l1 !== null && l2 !== null) {
      if (l1.val <= l2.val) {
        push(merged, l1.val);
        push(merged, l2.val);
      } else {
        push(merged, l2.val);
        push(merged, l1.val);
      }
      l1 = l1.next;
      l2 = l2.next;
    }
    if (l1 !== null && l2 === null) {
      push(merged, l1.val);
      l1 = l1.next;
    }
    if (l1 === null && l2 !== null) {
      push(merged, l2.val);
      l2 = l2.next;
    }
  }

  return merged;
}

let l1 = new ListNode(1);
push(l1, 2);
push(l1, 4);
push(l1, 77);

let l2 = new ListNode(1);
push(l2, 3);
push(l2, 4);
push(l2, 88);
push(l2, 100);
push(l2, 150);

const merged = mergeLists(l1, l2);
printList(merged); 