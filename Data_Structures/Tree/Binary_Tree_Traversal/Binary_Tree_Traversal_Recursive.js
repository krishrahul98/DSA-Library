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
    const result = [];
    f(this.root, result);
    return result;
  }

  preOrder() {
    return this.visit(preOrderVisit);
  }

  postOrder() {
    return this.visit(postOrderVisit);
  }

  inOrder() {
    return this.visit(inOrderVisit);
  }
}

const buildTree = () => {
  const node7 = new Node({value: 7});
  const node6 = new Node({value: 6});
  const node5 = new Node({value: 5});
  const node4 = new Node({value: 4, right: node7});
  const node2 = new Node({value: 2, left: node4, right: node5});
  const node3 = new Node({value: 3, right: node6});
  const node1 = new Node({value: 1, left: node2, right: node3});
  return node1;
};

const main = () => {
  const tree = new BinaryTree(buildTree());
  console.log("tree =",tree);
  console.log("pre-order", tree.preOrder());
  console.log("post-order", tree.postOrder());
  console.log("in-order", tree.inOrder());
};

main();
