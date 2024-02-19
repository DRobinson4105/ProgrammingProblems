from math import sqrt


w1, h1 = map(int, input().split())
w1, h1 = max(w1, h1), min(w1, h1)
w2, h2 = map(int, input().split())
w2, h2 = max(w2, h2), min(w2, h2)
w3, h3 = map(int, input().split())
w3, h3 = max(w3, h3), min(w3, h3)

side = int(sqrt(w1 * h1 + w2 * h2 + w3 * h3))
arr = [(w1, h1), (w2, h2), (w3, h3)]
arr.sort(key=lambda x: -x[0])

biggest = arr[0]
if biggest[0] != side:
    print(0)
    exit()

need = biggest[1]

if (
    (arr[1][0] + arr[2][0] == side and arr[1][1] == arr[2][1] == side - need) or
    (arr[1][0] + arr[2][1] == side and arr[1][1] == arr[2][0] == side - need) or
    (arr[1][1] + arr[2][0] == side and arr[1][0] == arr[2][1] == side - need) or
    (arr[1][1] + arr[2][1] == side and arr[1][0] == arr[2][0] == side - need) or
    (arr[1][0] == arr[2][0] == side and arr[1][1]  + arr[2][1] == side - need)
):
    print(1)
else:
    print(0)