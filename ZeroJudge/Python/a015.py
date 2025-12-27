"""
內容
已知一(m x n)矩陣A，我們常常需要用到另一個將A中之行與列調換的矩陣。這個動作叫做矩陣的翻轉。舉例來說，若

A =	[	3	1	2	]
8	5	4
則

AT =	[	3	8	]
1	5
2	4

現在 請您針對所讀取到的矩陣進行翻轉。

輸入說明
第一行會有兩個數字，分別為 列(row)<100 和 行(column)<100，緊接著就是這個矩陣的內容

輸出說明
直接輸出翻轉後的矩陣

範例輸入 #1
2 3
3 1 2
8 5 4
範例輸出 #1
3 8
1 5
2 4

提示 ：
* 測資檔會包含多組矩陣資料
"""
# 因為測資檔會包含多組矩陣資料,所以需寫while並增加try except
try:
    while 1:
        # 輸入矩陣規則 r(row),c(column)
        r, c = map(int, input().split(" "))
        # 建立空矩陣
        matrix = []
        for i in range(r):
            matrix.append(input().split(" "))
        # 定義翻轉函式
        def flip(m, row, column):
            for j in range(column):
                for k in range(row):
                    print(m[k][j], end=" ")
                print("")
            return 0
        # 放入參數呼叫函式
        ans = flip(matrix, r, c)
except EOFError:
    pass
