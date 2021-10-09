/*
  The levelOrderTraversal function is specific to the binary tree structure specified in lines 5 through 15.
  (i.e it assumes that the root is never null)
*/

class Node {
  constructor({value, left, right}) {
    this.value = value;
    this.left = left;
    this.right = right;
  }
}

const preOrderVisit = (node, buffer) => {
  if (node !== undefined) {
    buffer.push(node.value);
    preOrderVisit(node.left, buffer);
    preOrderVisit(node.right, buffer);
  }
}

const postOrderVisit = (node, buffer) => {

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
  const node5 = new Node({value: 5});
  const node4 = new Node({value: 4});
  const node2 = new Node({value: 2, left: node4, right: node5});
  const node3 = new Node({value: 3});
  const node1 = new Node({value: 1, left: node2, right: node3});
  return node1;
};

const main = () => {
  const tree = new BinaryTree(buildTree());
  console.log(tree);
  console.log(tree.preOrder());
};

main();
