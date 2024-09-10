t = int(input(''))
while t:
    t-=1    
    n = int(input())

    l  = list(map(int,input().split()))

    d = int(input())

    ch = []

    # 計算前綴和
    prefix_sum = [0] * (len(l) + 1)

    for i in range(1, len(l) + 1):
        prefix_sum[i] = prefix_sum[i - 1] + l[i - 1]

    # 儲存結果
    ch = []

    # 利用前綴和計算子陣列的和並取模
    for i in range(len(l)):
        for j in range(i + 1, len(l) + 1):
            # 子陣列 l[i:j] 的和為 prefix_sum[j] - prefix_sum[i]
            ch.append((prefix_sum[j] - prefix_sum[i]) % d)

    
    
    print(ch.__len__())
