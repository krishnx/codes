class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None


class Tree:
    def __init__(self, root):
        self.root = root

    def insert_node(self, data):
        if not self.root:
            self.root = Node(data)
        else:
            tmp = self.root
            while tmp:
                if tmp.data <= data:
                    if tmp.right:
                        tmp = tmp.right
                    else:
                        tmp.right = Node(data)

                        break
                elif tmp.data > data:
                    if tmp.left:
                        tmp = tmp.left
                    else:
                        tmp.left = Node(data)
                        break

    def inorder_traversal(self):
        if not self.root:
            return
        tmp = self.root
        stack = []
        res = []
        while True:
            if tmp:
                stack.append(tmp)
            elif stack:
                tmp = stack.pop()
                res.append(tmp.data)
                tmp = tmp.right
            else:
                break
        return res

    def search_node(self, data):
        if not self.root:
            return None
        tmp = self.root
        while tmp:
            if tmp.data > data:
                tmp = tmp.left
            elif tmp.data <= data:
                tmp = tmp.right
            else:
                return tmp

    def min_key(self, node):
        if not node:
            return None
        while node.left:
            node = node.left
        return node

    def delete_node(self, data):
        curr = self.root
        parent = None
        while curr and curr.data != data:
            parent = curr
            if curr.data < data:
                curr = curr.right
            else:
                curr = curr.left
        if not curr:
            return None

        if not (curr.left and curr.right):
            if curr != self.root:
                if parent.left == curr:
                    parent.left = None
                else:
                    parent.right = None
            else:
                self.root = None
            del curr
        elif curr.left and curr.right:
            successor = self.min_key(curr)
            val = successor.data
            self.delete_node(val)
            curr.data = val
        else:
            child = curr.left or curr.right

            if curr != self.root:
                if curr == parent.left:
                    parent.left = child
                else:
                    parent.right = child
            else:
                self.root = child
