"""
輸入說明
輸入若干行直到 EOF 為止。每一行包含一個十進位的整數

輸出說明
針對每一行的整數輸出其二進位制的結果
"""
# 方法：將十進位整數連除以2，直到商數為0，再從下往上依次取出餘數
try:
    while 1:
        n = int(input())
        ans = []
        while 1:
            ans.append(n % 2)
            n //= 2
            if n == 0:
                break
        ans.reverse()
        ans = map(str, ans)
        print("".join(ans))
except EOFError:
    pass