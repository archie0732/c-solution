def main():
    s: str = input()

    mid = int(len(s) / 2)
    n = len(s)

    # print(f"mid: {mid}")
    # aba mid = 3/2 = 1
    """
        ababa -> Yes
        abaaba -> No
    """

    for i in range(mid, n):

        head = s[0 : i + 1]
        button = s[n - len(head) : n]

        if head == button and len(head) != n:
            print(f"YES\n{head}")
            return

    print("NO")


main()
