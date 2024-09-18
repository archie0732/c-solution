def KMP_search(text: str, sub: str):
    # text 被搜索 -> 主串
    # sub 關鍵字 -> 子串

    # 建立 next 子串
    next = buildNext(sub)  # next 表示 發現前子串配對不瞭時可以跳過的數量

    i, j = 0, 0  # i 主串指針 j 子串指針

    while i < len(text):
        if text[i] == sub[j]:
            i += 1
            j += 1
        elif j > 0:
            j = next[j - 1]
        else:
            i += 1
        if j == len(sub):
            return f"找到字串，位於 {i - j} ~ {i}"
    return f"未找到{sub}"


def buildNext(s: str):
    next = [0]
    prefixLen = 0
    i = 1

    while i < len(s):
        if s[prefixLen] == s[i]:
            prefixLen += 1
            next.append(prefixLen)
            i += 1
        else:
            prefixLen = next[prefixLen - 1]
            if prefixLen == 0:
                next.append(0)
                i += 1
    return next


# test area
s = input("輸入文字: ")
sub = input("輸入查找文字: ")

print(KMP_search(s, sub))
