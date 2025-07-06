"""
給定兩個整數，請求出它們的最大公因數

輸入說明
輸入包含兩個整數，以空白鍵隔開，兩個整數均 大於 0, 小於 2 ** 31

輸出說明
輸出兩個整數的最大公因數
"""
# 輾轉相除法 用遞迴讓被除數(a)、除數(b) 互換
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)
a, b = map(int, input().split())
if a < b:
    a, b = b, a
print(gcd(a, b))
