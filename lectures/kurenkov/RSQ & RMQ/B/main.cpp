n = int(input())
a = list(map(int, input().split()))
res = []
for i in a:
while i%2 == 0:
i //= 2
res.append(i)
print(len(set(res)))