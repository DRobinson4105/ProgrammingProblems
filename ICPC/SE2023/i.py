from math import ceil

n, m, s, p, q = map(int, input().split())
numSections = ceil(n / m)
lowSec = 100000
hiSec = -1
preSelected = [set() for _ in range(numSections + 1)]
wantToSelect = [set() for _ in range(numSections + 1)]
total = 0
pagesToChange = []

for _ in range(p):
    item = int(input())
    page = ceil(item / m)
    preSelected[page].add(item)

for sec in range(q):
    item = int(input())
    page = ceil(item / m)
    wantToSelect[page].add(item)

for i in range(numSections + 1):
    if preSelected[i] != wantToSelect[i]:
        pagesToChange.append(i)
        if lowSec > 1000:
            lowSec = i
        hiSec = i

if lowSec > 1000:
    print(0)
    exit()

total += min(abs(s - lowSec), abs(s - hiSec)) + (hiSec - lowSec)

for i in pagesToChange:
    prob = 2000000
    itemsInPage = m if i < numSections else n % m
    if itemsInPage == 0: itemsInPage = m
    # Deselect all and select needed
    prob = min(prob, 1 + len(wantToSelect[i]))

    # Select all and deselect not needed
    prob = min(prob, 1 + itemsInPage - len(wantToSelect[i]))

    # Unselect and select what we need to change
    prob = min(prob, len(wantToSelect[i].union(preSelected[i]))
               - len(wantToSelect[i].intersection(preSelected[i])))
    total += prob

print(total)