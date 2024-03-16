n , k = map(int, input().split())
names = []
for _ in range(n):
    name, val = input().split()
    names.append((name, int(val)))

names.sort(key=lambda x: -x[1])
num, res = 0, list()
for name, val in names:
    if val <= k:
        num += 1
        res.append(name)
        k -= val
if k != 0:
    print(0)
    exit()

print(num)
print(*res, sep='\n')