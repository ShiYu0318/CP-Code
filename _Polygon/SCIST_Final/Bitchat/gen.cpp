#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    // 題目基本參數
    int N = rnd.next(9000, 10000);          // 裝置數量
    int R = rnd.next(250, 300);         // 最遠可連接距離
    int T = rnd.next(7, 10);          // 最多跳數
    cout << N << " " << R << " " << T << '\n';

    // 藍芽裝置座標
    for (int i = 0; i < N; ++i) {
        int x = rnd.next(-10000, 10000);
        int y = rnd.next(-10000, 10000);
        cout << x << " " << y << '\n';
    }

    int Q = rnd.next(40, 50); // 查詢次數
    cout << Q << '\n';

    int op_sub = 1;// atoi(argv[1]); // 支援的最大操作類型 (1 = 子題1, 2 = 子題2, 3 = 子題3)
    for (int i = 0; i < Q; ++i) {
        int op = (op_sub == 3 ? rnd.next(1, 2): op_sub);
        int a = rnd.next(1, N);
        int b = rnd.next(1, N);
        while (b == a) b = rnd.next(1, N); // 避免 a == b
        cout << op << " " << a << " " << b << '\n';
    }
    return 0;
}
