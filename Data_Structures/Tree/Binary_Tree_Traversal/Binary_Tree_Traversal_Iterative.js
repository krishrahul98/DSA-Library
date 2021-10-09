
class Node {
  constructor({value, left, right}) {
    this.value = value;
    this.left = left;
    this.right = right;
  }
}

/**
 * Visit the Node itself, then Left and Right.
 */
const preOrderVisit = (node, buffer) => {
  if (node !== undefined) {
    buffer.push(node.value);
    preOrderVisit(node.left, buffer);
    preOrderVisit(node.right, buffer);
  }
}

/**
 * Visit Left and Right, then the Node itself.
 */
const postOrderVisit = (node, buffer) => {
  if (node !== undefined) {
    postOrderVisit(node.left, buffer);
    postOrderVisit(node.right, buffer);
    buffer.push(node.value);
  }
}

/**
 * Visit Left, then the Node itself, and ends with Right.
 */
const inOrderVisit = (node, buffer) => {
  if (node !== undefined) {
    inOrderVisit(node.left, buffer);
    buffer.push(node.value);
    inOrderVisit(node.right, buffer);
  }
}

class BinaryTree {
  constructor(root) {
    this.root = root;
  }

  visit(f) {
  }

  preOrder() {
    const result = [];
    const stack = [this.root];
    while (stack.length > 0) {
      const node = stack.shift();
      if (node !== undefined) {
        result.push(node.value);
        stack.push(node.left, node.right);
      }
    }
    return result;
  }

  postOrder() {
    const result = [];
    const stack = [this.root];
    while (stack.length > 0) {
      const node = stack.shift();
      if (node !== undefined) {
        result.unshift(node.value);
        stack.push(node.right, node.left);
      }
    }
    return result;
  }

  inOrder() {
    const result = [];
    const stack = [];
    let node = this.root;
    do {
      while (node !== undefined) {
        stack.push(node);
        node = node.left;
      }

      if (stack.length > 0) {
        node = stack.pop();
        result.push(node.value);
        node = node.right;
      }
    } while (stack.length > 0 || node !== undefined);
    return result;
  }
}

const buildTree = () => {
  const node6 = new Node({value: 6});
  const node5 = new Node({value: 5});
  const node4 = new Node({value: 4});
  const node2 = new Node({value: 2, left: node4, right: node5});
  const node3 = new Node({value: 3/*, right: node6*/});
  const node1 = new Node({value: 1, left: node2, right: node3});
  return node1;
};

const main = () => {
  const tree = new BinaryTree(buildTree());
  console.log(tree);
  console.log(tree.preOrder());
  console.log(tree.postOrder());
  console.log(tree.inOrder());
};

main();
