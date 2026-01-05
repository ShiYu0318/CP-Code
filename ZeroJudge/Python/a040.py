"""
所謂 Armstrong number 指的是一個 n 位數的整數，它的所有位數的 n 次方和恰好等於自己。

如；1634 =

請依題目需求在一定範圍內找出該範圍內的所有 armstrong numbers.

輸入說明
輸入共一行包含兩個數字n, m(n<m, n>0, m<=1000000)，代表所有尋找 armstrong number 的範圍

輸出說明
將所有範圍內的 armstrong number 升冪輸出，如果沒有找到請輸出 none.
"""
min, max = map(int, input().split())
nums = []
for i in range(min, max):
    n = list(map(int, list(str(i))))
    sum = 0
    for j in n:
        sum += j ** len(n)
    if sum == i:
        nums.append(i)
    else:
        continue
if len(nums) == 0:
    print("none")
else:
    for i in nums:
        print(i,end=" ")