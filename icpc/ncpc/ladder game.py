def main() -> None:
    n, m = map(int, input().split())
    n = 2 * n - 1

    # 初始化水平线段
    grap = [input().strip() for _ in range(m)]

    # 构建图
    from collections import defaultdict, deque

    graph = defaultdict(list)
    for i in range(m):
        for j in range(1, n, 2):
            if grap[i][j] == "_":
                graph[j].append(j + 1)

    # 使用匈牙利算法找最大匹配
    def bfs():
        queue = deque()
        for u in range(1, n, 2):
            if match[u] == 0:
                dist[u] = 0
                queue.append(u)
            else:
                dist[u] = float("inf")
        dist[0] = float("inf")

        while queue:
            u = queue.popleft()
            if dist[u] < dist[0]:
                for v in graph[u]:
                    if dist[match[v]] == float("inf"):
                        dist[match[v]] = dist[u] + 1
                        queue.append(match[v])
        return dist[0] != float("inf")

    def dfs(u):
        if u != 0:
            for v in graph[u]:
                if dist[match[v]] == dist[u] + 1:
                    if dfs(match[v]):
                        match[v] = u
                        match[u] = v
                        return True
            dist[u] = float("inf")
            return False
        return True

    match = [0] * (n + 1)
    dist = [0] * (n + 1)
    matching_size = 0

    while bfs():
        for u in range(1, n, 2):
            if match[u] == 0 and dfs(u):
                matching_size += 1

    print(matching_size)


t = int(input())

while t:
    t -= 1
    main()
