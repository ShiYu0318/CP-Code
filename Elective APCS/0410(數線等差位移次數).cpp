#include <bits/stdc++.h>
using namespace std;
// 111329 黃士育
signed main()
{
    // 1
    int n=0,start,end,move,i;
    cin >> start >> end >> move;
    for(i=start;i<=end;i+=move) n++; 
    cout << "第" << n << "次移動到" << i << '\n';
    // 2
    cin >> start >> end >> move;
    int d=1;
    for(i= start+move;i<=end;i+=move)
    {
        cout << "第" << d << "天看了" << move << "頁，現在看到了第" << i << "頁" << '\n';
        move+=2;
        d++;
    }
    cout << "第" << d << "天看了" << move << "頁，現在看到了第" << i << "頁" << '\n';
}