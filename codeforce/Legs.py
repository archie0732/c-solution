def main():
    n = int(input())
    (d, m) = divmod(n, 4)
    print(d + m // 2 + (m % 2))


t = int(input())
for _ in range(t):
    main()
