#include<bits/stdc++.h>
using namespace std;
/*
5/29
113 29 黃士育
輸入所得淨額用else if判斷並求稅金
*/
signed main()
{
    long long m,tax;
    cout << "請輸入所得淨額：";
    cin >> m;
    if(m <= 560000) tax = m * 0.05;
    else if(m <= 1260000) tax = m * 0.12 - 39200;
    else if(m <= 2520000) tax = m * 0.2 - 140000;
    else if(m <=  4720000) tax = m * 0.3 - 392000;
    else tax = m * 0.4 - 864000;
    cout << "稅金 = " << tax << "\n\n";

    float w,f;
    cout << "請輸入用水度數：";
    cin >> w;
    if(w <= 20) f = w * 7.35;
    else if(w <= 60) f = w * 9.45 - 42;
    else if(w <= 100) f = w * 11.55 - 168;
    else f = w * 12.075 - 220.5;
    cout << "水費 = " << f << "\n\n";
}