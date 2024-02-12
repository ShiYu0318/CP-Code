def move(xy,s):
    if s == "L":
        return [xy[0] - 1,xy[1]]
    elif s == "R":
        return [xy[0] + 1,xy[1]]
    elif s == "U":
        return [xy[0],xy[1] + 1]
    elif s == "D":
        return [xy[0],xy[1] - 1]
n = int(input())
for i in range(n):
    b = False
    xy = [0, 0]
    count = input()
    step = list(input())
    for j in step:
        xy = move(xy,j)
        if xy == [1,1]:
            print("YES")
            b = True
            break
    if b:
        continue
    else:
        print("NO")