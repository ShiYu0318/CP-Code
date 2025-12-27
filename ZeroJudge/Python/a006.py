"""
求一元二次方程式 ax2+bx+c=0 的根

輸入說明
每組輸入共一行，內含三個整數 a, b, c 以空白隔開。

輸出說明
Two different roots x1=?? , x2=??

Two same roots x=??

No real root

PS: 答案均為整數，若有兩個根則大者在前
"""
import math     # 導入math函式庫
a, b, c = map(int, input().split(" "))
D = b ** 2 - 4 * a * c  # 計算判別式
if D > 0:   # 判別式 > 0 時， x 有相異實數解
    x1 = int((-b + math.sqrt(D)) / (a * 2))     # 公式解求值
    x2 = int((-b - math.sqrt(D)) / (a * 2))
    print(f"Two different roots x1={x1} , x2={x2}")
elif D == 0:    # 判別式 = 0 時， x 有一解（重根）
    x = int(-b / (a * 2))
    print(f"Two same roots x={x}")
else:   # 判別式 < 0 時， x 無解
    print("No real root")