"""
各位在國小時都學過因數分解，都瞭解怎麼樣用紙筆計算出結果，現在由你來敎電腦做因數分解。
因數分解就是把一個數字，切分為數個質數的乘積，如 12=2^2 * 3
其中, 次方的符號以 ^ 來表示
"""
from collections import Counter
n = int(input())
x = 2
nl = []
# 因數分解後將所有因數存入list
if n == 1:
    print("1")
else:
    while n >= 2:
        while n % x == 0:
            nl.append(x)
            n /= x
        x += 1
count = Counter(nl)  # 用Counter()計算列表中各個值出現的次數
s = ''
t = 0
# 輸出格式化
for i in count:
    if count[i] == 1:
        s += str(i)
    else:
        s += str(i) + "^" + str(count[i])
    t += 1
    if t != len(count):
        s += " * "
print(s)