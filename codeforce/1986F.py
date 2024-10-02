import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)

# Initialize variables/constants
N = 3 * 10**5 + 5
mod = 10**9 + 7

# Initialize variables
e = defaultdict(list)
e2 = defaultdict(list)
vdcc = []
dfsn = [0] * N
low = [0] * N
tot = 0
b = [0] * N
sz = [0] * N
s = []
ans = 10**18


def add(u, v, i):
    e[u].append((v, i))
    e[v].append((u, i))


def tarjan(x, f):  # 邊雙連通分量
    global tot
    dfsn[x] = low[x] = tot = tot + 1
    s.append(x)
    for u, i in e[x]:
        if not dfsn[u]:
            tarjan(u, i)
            low[x] = min(low[x], low[u])
        elif f != i:
            low[x] = min(low[x], dfsn[u])
    if dfsn[x] == low[x]:  # 邊雙區域
        c = []
        while True:  # 結算區塊
            t = s.pop()
            b[t] = len(vdcc)
            sz[len(vdcc)] += 1
            c.append(t)
            if t == x:  # 子節點至邊雙區域開始
                break
        vdcc.append(c)


def init():
    global tot, e, e2, dfsn, b, sz, vdcc
    tot = 0
    e = defaultdict(list)
    e2 = defaultdict(list)
    dfsn = [0] * N
    b = [0] * N
    sz = [0] * N
    vdcc = []


def dfs(x, f):
    global ans
    sum_v = 0
    for u in e2[x]:
        if u != f:
            sum_v += dfs(u, x)
    sum_v += sz[x]
    res = n - sum_v
    ans = min(ans, sum_v * (sum_v - 1) // 2 + (res - 1) * res // 2)
    return sum_v


def solve():
    global n, ans
    n, m = map(int, input().split())
    init()
    ans = 10**18
    for i in range(1, m + 1):
        u, v = map(int, input().split())
        add(u, v, i)

    for i in range(1, n + 1):
        if not dfsn[i]:
            tarjan(i, -1)

    for i in range(1, n + 1):
        for j, id in e[i]:
            if b[i] != b[j]:
                e2[b[i]].append(b[j])

    dfs(b[1], -1)
    print(ans)


# Main function to run the program
def main():
    t = 1
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
