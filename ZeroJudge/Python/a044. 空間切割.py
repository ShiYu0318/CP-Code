"""
對任意正整數n，空間中的n 個平面最多可將空間切成幾個區域？

輸入說明
輸入若干行直到 EOF 為止。每一行包含一個正整數 n

輸出說明
針對每一個 n ，輸出切割出的區域數。
"""
while 1:
    try:
        n = int(input())
        print(int((n ** 3 + 5 * n + 6) / 6))
    except EOFError:
        break