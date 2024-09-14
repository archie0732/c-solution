# 勾使
class A7Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y


# 內積
def a7Cross(p1: A7Point, p2: A7Point, p3: A7Point) -> int:

    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x)


# 判斷點 p 是否在線段 p1, p2 上 -> 如果確定在點上，直接結束。因為位於點上無論怎麼連線都會相交
def isOnSameLine(p1: A7Point, p2: A7Point, p: A7Point) -> bool:
    return min(p1.x, p2.x) <= p.x <= max(p1.x, p2.x) and min(p1.y, p2.y) <= p.y <= max(
        p1.y, p2.y
    )


# 判斷兩條線段 (p1, p2) 和 (p3, p4) 是否相交 -> 由同、不同側解決
def isIntersecting(p1: A7Point, p2: A7Point, p3: A7Point, p4: A7Point) -> bool:

    d1 = a7Cross(p3, p4, p1)
    d2 = a7Cross(p3, p4, p2)
    d3 = a7Cross(p1, p2, p3)
    d4 = a7Cross(p1, p2, p4)

    if d1 * d2 < 0 and d3 * d4 < 0:
        return True

    # 檢查重疊
    if d1 == 0 and isOnSameLine(p3, p4, p1):
        return True
    if d2 == 0 and isOnSameLine(p3, p4, p2):
        return True
    if d3 == 0 and isOnSameLine(p1, p2, p3):
        return True
    if d4 == 0 and isOnSameLine(p1, p2, p4):
        return True

    return False


"""
# 單元測試
 
red_start = Point(3, 0)
red_end = Point(7, 5)
green_start = Point(2, 4)
green_end = Point(3, 1)

it("msut be false",aync() => {
    expect(isIntersecting(red_start,red_end,green_start,green_end)).toBe(False)
})

"""


# main
def main() -> None:
    gril = list(map(int, input().split()))
    red = [A7Point(gril[i], gril[i + 1]) for i in range(0, len(gril), 2)]

    boy = list(map(int, input().split()))
    green = [A7Point(boy[i], boy[i + 1]) for i in range(0, len(boy), 2)]

    # 女生畫一條線:V
    for i in range(len(red) - 1):
        for j in range(i + 1, len(red)):
            # 列舉每個線段交點狀況
            A01 = isIntersecting(red[i], red[j], green[0], green[1])
            A02 = isIntersecting(red[i], red[j], green[0], green[2])
            A03 = isIntersecting(red[i], red[j], green[0], green[3])
            A12 = isIntersecting(red[i], red[j], green[1], green[2])
            A13 = isIntersecting(red[i], red[j], green[1], green[3])
            A23 = isIntersecting(red[i], red[j], green[3], green[2])

            # 只要男生有【任意一點連結其他三點的三條線】都與V相交，則男生必輸。反之條件不足，男生必贏
            if (
                (A01 and A02 and A03)
                or (A12 and A01 and A13)
                or (A23 and A02 and A12)
                or (A23 and A03 and A13)
            ):
                print("G")
                return

    print("B")
    return


# program start:
t = int(input())

while t:
    t -= 1
    main()

# ncpc mdfk
