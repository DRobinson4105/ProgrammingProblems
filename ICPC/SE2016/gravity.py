n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]

for i in range(n - 1, -1, -1):
    for c in range(m):
        if arr[i][c] != 'o': continue
        r = i + 1
        while r < n and arr[r][c] == '.':
            r += 1
        arr[i][c] = '.'
        arr[r-1][c] = 'o'

for i in arr:
    print(''.join(i))