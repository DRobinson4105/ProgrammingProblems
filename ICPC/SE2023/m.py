n = input()
cur = 1
while n:
    if n.startswith(str(cur)):
        n = n[len(str(cur)):]
        cur+=1
    else:
        print(-1) 
        exit()
else:
    print(cur - 1)