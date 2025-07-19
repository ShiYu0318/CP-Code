RCM = list(map(int, input().split()))  #input矩陣規則
R = RCM[0]  #row
C = RCM[1]  #column
M = RCM[2]  #對矩陣操作(0:旋轉 ;1:翻轉)
rows = []
#input完整矩陣
for i in range(1, R + 1):
  row = list(map(int, input().split()))  #字串轉int list
  rows.append(row)  #把矩陣變成二維list
#定義矩陣旋轉函式
def rotate(list):
  new_rows = []
  R = len(list)
  C = len(list[0])
  for i in range(C):
    row = []
    for j in range(R):
      row.append(list[R-1-j][i])
    new_rows.append(row)
  return new_rows
#定義矩陣翻轉函式
def flip(list):
  new_rows = []
  R = len(list)
  for i in range(R):
    new_rows.append(list[R - 1 - i])
  return new_rows
#input最後一行 呼叫函示操作矩陣
Ms = input().split() 
for i in Ms:
  if i == '0':
    rows = rotate(rows)
  if i == '1':
    rows = flip(rows)
#output
print(f'{len(rows)} {len(rows[0])}')
for row in rows:
  for num in row:
    print(num,end=' ')
  print()