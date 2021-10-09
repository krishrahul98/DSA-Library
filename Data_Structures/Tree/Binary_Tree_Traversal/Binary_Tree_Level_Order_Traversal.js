/*
  The levelOrderTraversal function is specific to the binary tree structure specified in lines 5 through 15.
  (i.e it assumes that the root is never null)
*/

class Node {
  constructor(value) {
    this.value = value;
    this.left = this.right = null;
  }
}

class binaryTree {
  constructor(value) {
    this.root = new Node(value);

    this.levelOrderTraversal = this.levelOrderTraversal.bind(this);
  }
  
  levelOrderTraversal() {
    const traversal = [];
    const queue = [];
    
    queue.push(this.root);

    while (queue.length > 0) {
      let currentLevel = [];
      let nodesInLevel = queue.length;

      while (nodesInLevel > 0) {
        let currentNode = queue.shift();

        if (currentNode.left !== null) {
          queue.push(currentNode.left)
        }

        if (currentNode.right !== null) {
          queue.push(currentNode.right)
        }

        currentLevel.push(currentNode.value);
        nodesInLevel--;
      }

      traversal.push(currentLevel);
    }

    return traversal;
  }
}
