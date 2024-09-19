I = input
for _ in [0] * int(I()):
    n = int(I())
    a = b, c = set(), set()
    for _ in [0] * n:
        x, y = I().split()
        a[y > "0"].add(int(x))
    print(
        len(b & c) * (n - 2)
        + sum(v >= {x - 1, x + 1} for u, v in (a, (c, b)) for x in u)
    )
