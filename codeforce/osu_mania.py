t = int(input())
s = []
for _ in range(t):
    n = int(input())
    ans = []
    for _ in range(n):
        tem = input()
        index = tem.index("#") + 1
        ans.append(index)
    ans.reverse()

    for i in ans:
        print(i, end=" ")
    print()
