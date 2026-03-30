a = 0 # 主隊贏的次數
b = 0 # 客隊贏的次數

for i in range(2):
    x = 0
    y = 0

    n = list(map(int,input().split(' ')))
    for i in range(4):
        x += n[i]
    n = list(map(int,input().split(' ')))
    for i in range(4):
        y += n[i]

    print(f"{x}:{y}")

    if x > y:
        a += 1
    else:
        b += 1

if a > b:
    print("Win")
elif a < b:
    print("Lose")
else:
    print("Tie")