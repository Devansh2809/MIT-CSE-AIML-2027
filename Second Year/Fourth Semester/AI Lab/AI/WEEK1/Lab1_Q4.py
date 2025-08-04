class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert_rec(self.root, key)

    def _insert_rec(self, root, key):
        if key < root.val:
            if root.left is None:
                root.left = Node(key)
            else:
                self._insert_rec(root.left, key)
        else:
            if root.right is None:
                root.right = Node(key)
            else:
                self._insert_rec(root.right, key)

    def pre_order(self, node):
        if node:
            print(node.val, end=' ')
            self.pre_order(node.left)
            self.pre_order(node.right)

    def in_order(self, node):
        if node:
            self.in_order(node.left)
            print(node.val, end=' ')
            self.in_order(node.right)

    def post_order(self, node):
        if node:
            self.post_order(node.left)
            self.post_order(node.right)
            print(node.val, end=' ')

if __name__ == "__main__":
    bst = BinarySearchTree()
    bst.insert(25)
    bst.insert(15)
    bst.insert(50)
    bst.insert(10)
    bst.insert(35)
    bst.insert(70)
    bst.insert(22)
    bst.insert(4)
    bst.insert(12)
    bst.insert(18)
    bst.insert(24)
    bst.insert(31)
    bst.insert(44)
    bst.insert(66)
    bst.insert(90)
    print("Pre-order traversal:")
    bst.pre_order(bst.root)
    print("\nIn-order traversal:")
    bst.in_order(bst.root)
    print("\nPost-order traversal:")
    bst.post_order(bst.root)
