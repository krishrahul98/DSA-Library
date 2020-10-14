/**
 * Reversing Linked List
}
 */
"use strict";

class LinkedListNode {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

let myListIterator = (LLN) => {
  let current = LLN;

  while (current.next) {
    // console.log({current});
    console.log(current.value);

    current = current.next;
  }
  // console.log({current});
  console.log(current.value);
};

let myListReverser = (LLN) => {
  if (!LLN) {
    return null;
  }
  if (LLN.next === null) {
    return LLN;
  }

  let current = LLN;
  let temp = {},
    previous = null;

  while (current && current.next) {
    temp = { ...current };

    current.next = previous;
    previous = current;
    current = temp.next;
  }
  // old tail is the new head;
  current.next = previous;
  return current;
};

const one = new LinkedListNode(1);
const two = new LinkedListNode(2);
const three = new LinkedListNode(3);
const four = new LinkedListNode(4);

one.next = two;
two.next = three;
three.next = four;

myListIterator(one);
console.log("\n ... \n");

let myNewHead = myListReverser(one);
console.log({ myNewHead });

console.log({ one });
console.log({ two });
console.log({ three });
console.log({ four });

console.log("\n ... \n");
myListIterator(myNewHead);

/*
 * Iterative Approach
 */

function reverse(headOfList) {
  let currentNode = headOfList;
  let previousNode = null;
  let nextNode = null;

  // Until we have 'fallen off' the end of the list
  while (currentNode) {
    // Copy a pointer to the next element
    // before we overwrite currentNode.next
    nextNode = currentNode.next;

    // Reverse the 'next' pointer
    currentNode.next = previousNode;

    // Step forward in the list
    previousNode = currentNode;
    currentNode = nextNode;
  }

  return previousNode;
}

/*
 * Bonus
 * This in-place ↴ reversal destroys the input linked list.
 * What if we wanted to keep a copy of the original linked list? Write a function for reversing a linked list out-of-place.
 */

function reverseOutOfPlace(headOfList) {
  let currentNode = headOfList;
  let previousNode = null;
  let nextNode = null;
  let newCurrent;

  while (currentNode) {
    nextNode = currentNode.next;

    newCurrent = new LinkedListNode(currentNode.value);
    newCurrent.next = previousNode;

    previousNode = newCurrent;

    currentNode = nextNode;
  }
  return newCurrent;
}

console.log("\n ... \n");

let five = new LinkedListNode(5);
let six = new LinkedListNode(6);
let seven = new LinkedListNode(7);
let eight = new LinkedListNode(8);

five.next = six;
six.next = seven;
seven.next = eight;

console.log({ five });
console.log({ six });
console.log({ seven });
console.log({ eight });

console.log("\n ... iterate new ll ... \n");
myListIterator(five);
console.log("\n ... reverseOutOfPlace ... \n");

myNewHead = reverseOutOfPlace(five);
console.log({ myNewHead });

console.log("\n ... reverseOutOfPlace ... \n");
myListIterator(myNewHead);

/**
 * https://leetcode.com/problems/reverse-linked-list/
 * Reverse a singly linked list.
Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
Success
Details
Runtime: 52 ms, faster than 99.89% of JavaScript online submissions for Reverse Linked List.
Memory Usage: 35.5 MB, less than 12.55% of JavaScript online submissions for Reverse Linked List.
*/

console.log("\n ... leet code linked list reverser... \n");

function ListNode(val) {
  this.val = val;
  this.next = null;
}

let lC_one = new ListNode(1);
let lC_two = new ListNode(2);
let lC_three = new ListNode(3);
let lC_four = new ListNode(4);
let lC_five = new ListNode(5);

lC_one.next = lC_two;
lC_two.next = lC_three;
lC_three.next = lC_four;
lC_four.next = lC_five;

console.log({ lC_one });
console.log({ lC_two });
console.log({ lC_three });
console.log({ lC_four });
console.log({ lC_five });

var reverseList = function (head) {
  if (!head || head === null) {
    return null;
  }
  let temp, prev;
  let curr = head;

  console.log({ curr });

  while (curr.next) {
    temp = { ...curr };

    console.log({ temp });

    curr.next = prev;
    prev = curr;
    curr = temp.next;
  }
  // tail
  curr.next = prev;

  return curr; // new head
};

reverseList(lC_one);

console.log("\n ... ... \n");

console.log({ lC_five });
console.log({ lC_four });
console.log({ lC_three });
console.log({ lC_two });
console.log({ lC_one });
