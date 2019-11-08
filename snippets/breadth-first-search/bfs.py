from queue import *

class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = []
        for i in range(V):
            self.adj.append([])

    def add_edge(self, v, w):
        self.adj[v].append(w)

    def add_bi_edge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)

    def bfs(self, start):
        visited = [False] * self.V
        bfs = Queue(maxsize=self.V)

        visited[start] = True
        bfs.put(start)

        while not bfs.empty():
            v = bfs.get()

            print(v, end=' ')

            for u in self.adj[v]:
                if not visited[u]:
                    visited[u] = True
                    bfs.put(u)

        print()
