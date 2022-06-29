import queue

A = 0  # Arad
B = 1  # Bucharest
C = 2  # Craiova
D = 3  # Dobreta
E = 4  # Eforie
F = 5  # Fagaras
G = 6  # Giurgiu
H = 7  # Hirsova
I = 8  # Iasi
L = 9  # Lugoj
M = 10  # Mehadia
N = 11  # Neamt
O = 12  # Oradea
P = 13  # Pitesti
R = 14  # Rimnicu Vilcea
S = 15  # Sibiu
T = 16  # Timisoara
U = 17  # Urziceni
V = 18  # Vaslui
Z = 19  # Zerind

CITY_LENGTH = 20

class Graph:
    def __init__(self):
        self.graph = [[0] * 20 for i in range(CITY_LENGTH)]

    def add_edge(self, _from, _to, value):
        if _from < CITY_LENGTH:
            if _to < CITY_LENGTH:
                self.graph[_from][_to] = value
                self.graph[_to][_from] = value

    def getEdge(self, _from, _to):
        return self.graph[_from][_to]

class Stack:
    def __init__(self):
        self.stack = []
        self.length = 0

    def push(self, value):
        self.stack.append(value)
        self.length += 1
        return

    def pop(self):
        self.length -= 1
        if (self.length >= 0):
            return self.stack.pop()
        else:
            return False

    def top(self):
        return self.stack[self.length - 1]

    def isEmpty(self):
        if self.stack:
            return False
        return True

class CloseQueue:
    def __init__(self):
        self.queue = []

    def put(self, value):
        self.queue.append(value)
        return

    def get(self):
        return self.queue.pop(0)

    def contain(self, value):
        return value in self.queue

    def isEmpty(self):
        if self.queue:
            return False
        return True

class OpenQueue:
    def __init__(self):
        self.queue = []

    def put(self, nodeCost):
        self.queue.append(nodeCost)

    def get(self):
        if self.queue:
            minCity = 0
            minCost = self.queue[minCity][1]
            for i in range(len(self.queue)):
                if self.queue[i][1] < minCost:
                    minCity = i
                    minCost = self.queue[i][1]
            return self.queue.pop(minCity)

    def contain(self, value):
        for i in range(len(self.queue)):
            if self.queue[i][0] == value:
                return self.queue[i],True
        return None,False

    def isEmpty(self):
        if self.queue:
            return False
        return True

def initGraph():
    graph = Graph()
    graph.add_edge(O, Z, 71)
    graph.add_edge(O, S, 151)
    graph.add_edge(A, Z, 75)
    graph.add_edge(A, S, 140)
    graph.add_edge(A, T, 118)
    graph.add_edge(T, L, 111)
    graph.add_edge(L, M, 70)
    graph.add_edge(M, D, 75)
    graph.add_edge(D, C, 120)
    graph.add_edge(S, R, 80)
    graph.add_edge(S, F, 99)
    graph.add_edge(R, C, 146)
    graph.add_edge(F, B, 211)
    graph.add_edge(R, P, 97)
    graph.add_edge(C, P, 138)
    graph.add_edge(P, B, 101)
    graph.add_edge(B, G, 90)
    graph.add_edge(B, U, 85)
    graph.add_edge(U, H, 98)
    graph.add_edge(U, V, 142)
    graph.add_edge(V, I, 92)
    graph.add_edge(I, N, 87)
    graph.add_edge(H, E, 86)
    return graph

def deepFirst(graph, _root, _goal):
    answer = Stack()
    cost = 0
    ergodicStack = Stack()
    ergodicStack.push(_root)

    while not ergodicStack.isEmpty():
        parent = ergodicStack.pop()
        answer.push(parent)
        if answer.length > 1:
            cost += graph.getEdge(answer.top(), answer.stack[answer.length-2])
        if parent == _goal:
            break
        for i in range(20):
            if graph.getEdge(parent,i) != 0:
                flag = True
                for t in answer.stack:
                    if t == i:
                        flag = False
                if flag == True:
                    ergodicStack.push(i)

    print(answer.stack)
    print(cost)
    print(answer.length)
def breadFirst(graph, _root, _goal):
    answer = Stack()
    cost = 0
    ergodicQueue = queue.SimpleQueue()
    ergodicQueue.put(_root)

    while not ergodicQueue.empty():
        parent = ergodicQueue.get()
        answer.push(parent)
        for i in range(20):
            if graph.getEdge(parent,i) != 0:
                flag = True
                for t in answer.stack:
                    if t == i:
                        flag = False
                if flag == True:
                    ergodicQueue.put(i)
                    cost += graph.getEdge(parent, i)
                    if i == _goal:
                        while not ergodicQueue.empty():
                            answer.push(ergodicQueue.get())
    for i in range(answer.length - 1):
        cost += graph.getEdge(answer.stack[i], answer.stack[i+1])
    print(answer.stack)
    print(cost)
    print(answer.length)

def aStar(graph, h, _root, _goal):
    parents = [0] * CITY_LENGTH
    openList = OpenQueue()
    closeList = CloseQueue()
    openList.put([_root, h[_root]])

    while openList.isEmpty() == False:
        parentNode = openList.get()

        if parentNode[0] == _goal:
            break

        closeList.put(parentNode[0])

        for i in range(20):
            length = graph.getEdge(parentNode[0], i)
            if length != 0:
                if closeList.contain(i):
                    continue

                node, result = openList.contain(i)
                f = parentNode[1] - h[parentNode[0]] + length + h[i]

                if result == True:
                    if node[1] > f:
                        for t in openList.queue:
                            if (t[0] == node[0]):
                                t[1] = node[1]
                        parents[i] = parentNode[0]
                else:
                    parents[i] = parentNode[0]
                    openList.put([i,f])

    path = []
    cost = 0
    p = _goal

    while p != _root:
        cost += graph.getEdge(p, parents[p])
        path.append(p)
        p = parents[p]

    length = len(path) - 1
    print('path:', _root, end='')
    for i in range(length + 1):
        print("-->", path[length - i], end='')
    print()
    print(cost)
    print(len(path)+1)
    print(openList.queue)
    print(closeList.queue)
def distance(x1, y1, x2, y2):
    return ((x1 - x2)**2 + (y1 - y2)**2)**0.5


graph = initGraph()

h = (distance(91,492,400,327),distance(400,327,400,327),distance(253,288,400,327),distance(165,299,400,327),distance(562,293,400,327)
     ,distance(305,449,400,327),distance(375, 270,400,327),distance(534, 350,400,327),distance(473, 506,400,327),distance(165, 379,400,327)
,distance(168, 339,400,327),distance(406, 537,400,327),distance(131, 571,400,327),distance(320, 368,400,327)
,distance(233, 410,400,327),distance(207, 457,400,327),distance(94, 410,400,327),distance(456, 350,400,327),distance(509, 444,400,327),distance(108, 531,400,327))

aStar(graph, h, eval('A'), eval('B'))
deepFirst(graph, eval('A'), eval('B'))
breadFirst(graph, eval('A'), eval('B'))