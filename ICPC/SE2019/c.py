r, c, v, h = map(int, input().split())
arr_v = [int(input()) for _ in range(v)]
arr_h = [int(input()) for _ in range(h)]
res = []

for ind, i in enumerate(arr_v):
    if ind % 2 == 0:
        cur = 'B'
    else:
        cur = 'W'
    string = ''
    for j in arr_h:
        string += cur * j
        cur = 'W' if cur == 'B' else 'B'
    for _ in range(i):
        res.append(string)

print(*res, sep='\n')