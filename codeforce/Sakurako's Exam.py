def main():
    one, two = map(int, input().split())
    # 列舉"可以"的情況
    if one != 0 and one % 2 == 0 or one + two == 0:
        print("YES")
    elif one == 0 and two % 2 == 0:
        print("YES")
    else:
        print("NO")


t = int(input())

for _ in range(t):
    main()
