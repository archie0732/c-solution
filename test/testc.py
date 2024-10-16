def find_triplet(arr):
    n = len(arr)
    if n < 3:
        return "no match"  # 不足三個元素，無法找到符合的三元組

    # Step 1: 預處理左邊最小值
    leftMin = [0] * n
    leftMin[0] = arr[0]
    for i in range(1, n):
        leftMin[i] = min(leftMin[i - 1], arr[i])

    # Step 2: 預處理右邊最大值
    rightMax = [0] * n
    rightMax[n - 1] = arr[n - 1]
    for i in range(n - 2, -1, -1):
        rightMax[i] = max(rightMax[i + 1], arr[i])

    # Step 3: 遍歷中間元素作為 j
    for j in range(1, n - 1):
        # 確保有一個左側最小值和右側最大值存在，且符合條件
        if leftMin[j - 1] < arr[j] > rightMax[j + 1]:
            # 在左側找到小於 arr[j] 的最大值
            i = -1
            for x in range(j - 1, -1, -1):
                if arr[x] < arr[j]:
                    i = x
                    break

            # 在右側找到小於 arr[j] 的最大值
            k = -1
            for x in range(j + 1, n):
                if arr[x] < arr[j]:
                    k = x
                    break

            if i != -1 and k != -1:
                return i, j, k

    return "no match"  # 沒有符合條件的三元組


a = find_triplet([1, 3, 4, 2, 5, 6])
print(a)
