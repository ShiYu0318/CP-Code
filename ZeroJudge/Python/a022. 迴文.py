"""
迴文的定義為正向，反向讀到的字串均相同

如：abba , abcba ... 等就是迴文

請判斷一個字串是否是一個迴文？

輸入說明
輸入資料共一行包含一個字串(長度 < 1000)

輸出說明
針對每一行輸入字串輸出 yes or no
"""
s = list(input())
if s == list(reversed(s)):
    print("yes")
else:
    print("no")