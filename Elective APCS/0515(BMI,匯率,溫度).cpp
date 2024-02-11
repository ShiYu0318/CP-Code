#include<bits/stdc++.h>
using namespace std;
/*
5/15
113 29 黃士育
階乘
*/
int main()
{
    float h,w,m,t;
    cout << "請輸入身高(cm) 體重(kg)：";
    cin >> h >> w;
    cout << "BMI = " << w / pow(h/100,2) << "\n\n";

    cout << "請輸入要換算的台幣：";
    cin >> m;
    cout << m << "台幣 = " << 0.033 * m << "美元\n\n";

    cout << "請輸入攝氏溫度(度C):";
    cin >> t;
    cout << "華氏溫度 = " << t * 9 / 5 + 32 << "\n\n";
}