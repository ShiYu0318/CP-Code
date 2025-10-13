# 賦值
n = input()

# n 算出有幾打 * 50 + 剩下幾枝 * 5
d = int(n) // 12
r = int(n) - d * 12

print(d * 50 + r * 5)