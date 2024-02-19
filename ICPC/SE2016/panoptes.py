# for _ in range(1000):
#     print(1)
# exit()
n, p = map(int, input().split())
nums = [float(input()) for _ in range(n)]
avg = .8 * sum(nums) / n

def test(i, st):
    # num = 0
    ind = i
    while ind < n:
        if nums[ind] >= avg:
            return False
        ind += st
        # num += 1
    # print(i, st)
    
    return True

res = n + 1
for i in range(n):
    if nums[i] < avg:
        step = p
        while step < res:
            if i - step < 0 and test(i, step):
                res = step
            step += 1

if res == n + 1:
    print(-1)
else:
    print(res)