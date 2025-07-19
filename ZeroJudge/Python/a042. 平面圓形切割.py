"""
對任意正整數n，平面上的n 個圓最多可將平面切成幾個區域？

輸入說明
輸入若干行直到 EOF 為止。每一行包含一個整數 n

輸出說明
針對每一個 n 輸出切割出的區域數。
"""
while 1:
    try:
        n = int(input())
        print(n ** 2 - n + 2)
    except EOFError:
        break