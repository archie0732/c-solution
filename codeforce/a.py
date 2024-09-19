l = [1, 2, 4, 5, 3]

for i in range(5):
    pre = -1
    cur = i
    ans = []
    while True:
        if l[cur] == l[i] and pre != -1:
            ans.append(cur + 1)
            break
        pre = cur
        ans.append(cur + 1)
        cur = l[cur] - 1
    print(ans)
