# 稀疏表模板

def main():
    from sys import stdin
    from itertools import islice
    e = stdin.readline
    
    n, q = map(int, e().split())
    
    # 建 log_2 表
    log_2 = [-1] * (n + 1)
    for i in range(1, n + 1):
        log_2[i] = log_2[i >> 1] + 1
    bl = log_2[-1] + 1  # n.bit_length()
    
    # 初始化稀疏表
    st = [None] * bl
    pre = st[0] = tuple(map(int, e().split()))
    
    # 稀疏表建表
    i2 = 1  # i * 2
    for i in range(1, bl):
        pre = st[i] = tuple(map(func, pre, islice(pre, i2, None)))
        i2 <<= 1
    
    # 稀疏表查表
    for _ in range(q):
        s, t = map(int, e().split())  # 查詢 [s, t) 區間
        r = log_2[t - s]
        row = st[r]
        print(func(row[s], row[t - (1 << r)]))
main()