test = [[0, 1], [1, 2], [2, 3], [0, 3]]
n = 4  # 點的數量


def Topology():
    degree = [0] * n
    road = {}

    # 建立層與路
    for i in test:
        if i[0] in road:
            road[i[0]].append(i[1])
        else:
            road[i[0]] = [i[1]]
        degree[i[1]] += 1
