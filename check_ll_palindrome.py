class Node:
    def __init__(self, data):
        self.data = data
        self.next_node = None


class LL:
    def __init__(self):
        self.head = None

    def traverse(self):
        tmp = self.head
        while tmp:
            print tmp.data
            tmp = tmp.next_node

    def push(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            new_node = Node(data)
            new_node.next_node = self.head
            self.head = new_node

    @staticmethod
    def reverse_ll(node):
        curr = node
        prev = None
        while curr:
            next_node = curr.next_node
            curr.next_node = prev
            prev = curr
            curr = next_node

        return prev

    @staticmethod
    def compare_ll(head1, head2):
        tmp1 = head1
        tmp2 = head2
        while tmp1 and tmp2:
            if tmp1.data != tmp2.data:
                return False
            tmp1 = tmp1.next_node
            tmp2 = tmp2.next_node

        if tmp1 and tmp2:
            return False

        return True

    def check_palindrome(self):
        slow = self.head
        fast = self.head

        while fast.next_node:
            fast = fast.next_node
            slow = slow.next_node
            if fast:
                fast = fast.next_node
            if not fast:
                break

        head1 = self.head
        head2 = self.reverse_ll(slow)
        return self.compare_ll(head1, head2)


l = LL()
s = ['a', 'b', 'a', 'c', 'a', 'b', 'a']

for i in range(len(s)):
    l.push(s[i])
    l.traverse()

    if l.check_palindrome():
        print("Is Palindrome")
    else:
        print("Not Palindrome")
