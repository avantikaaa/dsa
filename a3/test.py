class Link:
    def __init__(self, v, nextPtr = None):
        self.v = v
        self.nextPtr = nextPtr

class LinkList:
    def __init__(self):
        self.head = None

def createNode(node, v):
    tmp = Link(v)
    tmp.next = node
    return tmp
l = LinkList()
c = createNode(l.head, 1)
c = createNode(l.head, 2)
c = createNode(l.head, 3)
while l.head is not None:
    print(l.v)
    l = l.nextPtr
