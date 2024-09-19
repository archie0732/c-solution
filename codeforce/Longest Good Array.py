def main():

    l, r = map(int, input().split())
    r -= l
    goal = r * 2
    ans = -1
    left = 1
    right = 1000000

    while left <= right:
        mid = (left + right) // 2
        if mid * (mid - 1) <= goal:
            ans = mid
            left = mid + 1
        else:
            right = mid - 1

    if r == 0:
        ans = 1
    elif r == 1:
        ans = 2

    print(ans)


a = int(input())

for _ in range(a):
    main()
