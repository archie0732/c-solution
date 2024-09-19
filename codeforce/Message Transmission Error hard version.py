s = input()
n = len(s)
next = [0, 0]
"""
類似於 KMP 中的 build next
透過一次的掃描來確定是否存在與頭相同的子字串(列一個不含頭)
"""
for i in range(1, n):
    index = next[-1]
    while index > 0 and s[index] != s[i]:
        index = next[index]
        # 根據 KMP 算法 這裡的index = next[-1] 及目前配對最大相同子列之"長度"
        # 如果找不到就回退子串
    next.append(index + (s[i] == s[index]))  # 目前的最大符合子列

if next[-1] > n // 2:
    print(f"YES\n{s[:next[-1]]}")
else:
    print("NO")
