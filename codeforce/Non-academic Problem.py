t = int(input())
for T in range(0, t):
    n, m = tuple(map(int, input().split()))
    used = [0] * n
    tt = [0] * n
    up = [0] * n
    ind = [0] * n
    subtree = [0] * n
    gr = [0] * n
    for i in range(0, n):
        gr[i] = []
    cur = 0
    for i in range(0, m):
        u, v = tuple(map(int, input().split()))
        u -= 1
        v -= 1
        gr[u].append(v)
        gr[v].append(u)
    dfs = []
    dfs.append((0, -1))
    ans = 0
    while len(dfs) > 0:
        v, p = dfs[len(dfs) - 1]
        if ind[v] == 0:
            used[v] = 1
            tt[v] = cur
            up[v] = cur
            cur += 1
            subtree[v] = 1
        if ind[v] == len(gr[v]):
            dfs.pop()
            if p != -1:
                up[p] = min(up[p], up[v])
                subtree[p] += subtree[v]
                if up[v] == tt[v]:
                    ans = max(ans, (n - subtree[v]) * subtree[v])
        else:
            u = gr[v][ind[v]]
            if used[u] == 1:
                if u != p:
                    up[v] = min(up[v], tt[u])
            else:
                dfs.append((u, v))
            ind[v] += 1
    print(n * (n - 1) // 2 - ans)
