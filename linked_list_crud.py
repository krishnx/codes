class Node:
    def __init__(self, x):
        self.data = x
        self.next_node = None

    def get_data(self):
        return self.data

    def set_data(self, x):
        self.data = x

    def get_next(self):
        return self.next_node

    def set_next(self, new_next):
        self.next_node = new_next


class LL:
    def __init__(self, head):
        self.head = head

    def insert_first(self, data):
        node = Node(data)
        node.set_next(self.head)

    def insert_last(self, data):
        tmp = self.head
        while not tmp.next_node:
            tmp = tmp.get_next()
        tmp.set_next(Node(data))

    def get_size(self):
        tmp = self.head
        size = 0
        while tmp:
            tmp = tmp.get_next()
            size += 1
        return size

    def search_node(self, data):
        if not data:
            return None
        tmp = self.head
        while tmp:
            if tmp.get_data() == data:
                return tmp
            tmp = tmp.get_next()
        if not tmp:
            return None

    def delete_node(self, data):
        if not self.head:
            return None

        curr = self.head
        prev = None
        while curr:
            if curr.get_data() == data:
                prev = curr
                curr = curr.get_next()
                prev.set_next(curr)
            else:
                curr = curr.get_next()
        if prev is None:
            return None
        return self.head
