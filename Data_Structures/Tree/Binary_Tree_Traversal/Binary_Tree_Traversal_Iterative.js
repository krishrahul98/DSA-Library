
class Node {
  constructor({value, left, right}) {
    this.value = value;
    this.left = left;
    this.right = right;
  }
}

const isNotEmpty = stack => stack.length > 0;

class BinaryTree {
  constructor(root) {
    this.root = root;
  }

  visit(f) {
  }

  preOrder() {
    const result = [];
    const stack = [];
    let node = this.root;
    do {
      while (node !== undefined) {
        result.push(node.value);
        stack.push(node);
        node = node.left;
      }

      if (isNotEmpty(stack)) {
        node = stack.pop();
        node = node.right;
      }
    } while (isNotEmpty(stack) || node !== undefined);
    return result;
  }

  postOrder() {
    const result = [];
    const stack = [];
    let node = this.root;
    let prev = undefined;
    do {
      while (node !== undefined) {
        stack.unshift(node);
        node = node.left;
      }

      while (node === undefined && isNotEmpty(stack)) {
        node = stack[0];
        if (node.right === undefined || node.right == prev) {
          result.push(node.value);
          stack.shift();
          prev = node;
          node = undefined;
        } else {
          node = node.right;
        }
      }
    } while (isNotEmpty(stack));
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

      if (isNotEmpty(stack)) {
        node = stack.pop();
        result.push(node.value);
        node = node.right;
      }
    } while (isNotEmpty(stack) || node !== undefined);
    return result;
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
