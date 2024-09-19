import math


def main():
    n = int(input())
    s = input()
    r = math.isqrt(n)
    if r * r != n:
        print("No")
        return

    head = ["1"] * r
    mid: list = ["1"] + ["0"] * (r - 2) + ["1"]
    ans = head + mid * (r - 2) + head
    ansStr = "".join(ans)
    if ansStr == s:
        print("Yes")
        return
    print("No")


t = int(input())

for _ in range(t):
    main()
