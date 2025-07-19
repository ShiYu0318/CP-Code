n = int(input())
xy1 = list(map(int,input().split()))
ds = []
for i in range(n-1):
  xy2 = list(map(int,input().split()))
  d = abs(xy1[0] - xy2[0]) + abs(xy1[1] - xy2[1])
  ds.append(d)
  xy1 = xy2
ds.sort()
print(f'{ds[-1]} {ds[0]}')