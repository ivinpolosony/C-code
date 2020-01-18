import pprint


def knapsack(items, maxWeight):
    maxWeight = maxWeight + 1
    pp = pprint.PrettyPrinter(depth=6, indent=4)
    itemsSize = len(items)
    cache = [[0] * maxWeight] * itemsSize

    for i in range(0, itemsSize):
        for j in range(0, maxWeight):
            currItemW = items[i]['w']
            currItemV = items[i]['v']
            prevBest = cache[i - 1][j]
            if i == 0 or j == 0:
                cache[i][j] = 0
            elif currItemW <= j:
                cache[i][j] = max(prevBest, currItemV + cache[i - 1][j - currItemW])
            else:
                cache[i][j] = prevBest

    # print(*cache, sep='\n')
    return cache


def printItems(cells, maxWeight, itemsCount):
    w = maxWeight
    res = cells[itemsCount - 1][maxWeight]
    # range(start, stop[, step])
    for i in range(itemsCount, 0, -1):
        if res <= 0:
            break
        if res == cells[i - 1][w - 1]:
            continue
        else:
            print("W:", items[i - 1]['w'], " v:", items[i - 1]['v'])
            res = res - items[i - 1]['v']
            w = w - items[i - 1]['w']

    print(res)


item = {}
items = [{'w': 1, 'v': 6}, {'w': 2, 'v': 10}, {'w': 3, 'v': 12}]
maxWeight = 5
ans = knapsack(items, maxWeight)
printItems(ans, maxWeight, len(items))
# assert ans == 22, "dddddddddd"
