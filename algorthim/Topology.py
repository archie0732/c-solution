class KahnTopology:
    def __init__(self, grap: list[list[int]], n) -> None:
        self.indegree = [0] * n
        self.grap = grap
        for i in range(n):
            for v in grap[i]:
                self.indegree[v] += 1
        self.queue = [u for u in range(n) if self.indegree[u] == 0]
        self.result = []

    def TopologySort(self):
        while self.queue:
            node = self.queue.pop(0)
            self.result.append(node)

            for nb in self.grap[node]:
                self.indegree[nb] -= 1
                if self.indegree[nb] == 0:
                    self.queue.append(nb)

        if len(self.result) == len(self.grap):
            return self.result
        else:
            return None
