class Dsu:  # 模板
    def __init__(self, n) -> None:
        self.parent = [i for i in range(n)]
        self.rank = [1] * n

    def find(self, x):

        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def merge(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1


# test area
"""
n = 10
dsu = Dsu(n)


dsu.merge(1, 2)
dsu.merge(3, 4)
dsu.merge(1, 4)
print(dsu.find(1))
print(dsu.find(2))
print(dsu.find(3))
print(dsu.find(4))
        
"""
