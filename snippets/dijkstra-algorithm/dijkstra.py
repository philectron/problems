from collections import *

class Graph(object):
    def __init__(self, V):
        self.Edge = namedtuple('Edge', 'dest weight')
        self.V = V
        self.adj = [[] for i in range(V)]

    def add_edge(self, src, dest, weight):
        e = self.Edge(dest, weight)
        self.adj[src].append(e)

    def add_bi_edge(self, u, v, weight):
        self.add_edge(u, v, weight)
        self.add_edge(v, u, weight)

    def dijkstra(self, src):
        dist = [float('inf') for i in range(self.V)]
        pred = [-1 for i in range(self.V)]
        visited = [False for i in range(self.V)]

        dist[src] = 0

        for count in range(self.V):
            u = self.min_distance(dist, visited)
            visited[u] = True

            for edge in self.adj[u]:
                if not visited[edge.dest]:
                    d = dist[u] + edge.weight
                    if (d < dist[edge.dest]):
                        dist[edge.dest] = d
                        pred[edge.dest] = u

        return (dist, pred)  ###

    def min_distance(self, dist, visited):
        min_dist = float('inf')
        min_vertex = 0

        for v in range(self.V):
            if (dist[v] < min_dist) and (not visited[v]):
                min_dist = dist[v]
                min_vertex = v

        return min_vertex
