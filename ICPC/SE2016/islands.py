from collections import deque


n, m = map(int, input().split())
grid = [input() for _ in range(n)]
visited = [[False] * m for _ in range(n)]

def bfs(i, j):
    q = deque([(i, j)])
    while q:
        R, C = q.popleft()
        for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            r, c = R + dr, C + dc
            if 0 <= r < n and 0 <= c < m and not visited[r][c] and grid[r][c] in 'LC':
                visited[r][c] = True
                q.append((r, c))

islands = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j] and grid[i][j] == 'L':
            islands += 1
            bfs(i, j)

print(islands)