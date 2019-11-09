from queue import *

class Graph(object):
    def __init__(self, V):
        self.V = V
        self.adj = [[] for i in range(V)]

    def add_edge(self, src, dest):
        self.adj[src].append(dest)

    def add_bi_edge(self, u, v):
        self.add_edge(u, v)
        self.add_edge(v, u)

    def bfs(self, src):
        visited = [False for i in range(self.V)]
        bfs = Queue(maxsize=self.V)

        visited[src] = True
        bfs.put(src)

        while not bfs.empty():
            v = bfs.get()

            print(v, end=' ')  ###

            for u in self.adj[v]:
                if not visited[u]:
                    visited[u] = True
                    bfs.put(u)

        print()  ###
