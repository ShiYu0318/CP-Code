#include<bits/stdc++.h>
using namespace std;
/*
6/5
113 29 黃士育
輸入三邊長求出面積並判斷是哪種三角形
海龍公式
*/
int main()
{
    float l[3],max=0,sum=0,s,A;
    cout << "請輸入 a b c 邊長：";
    for(int i=0;i<3;i++)
    {
        cin >> l[i];
        if(l[i] > max) max = l[i];
        sum += l[i];
    }
    if(sum - max < max) cout << "不是三角形\n";
    else
    {
        s = sum / 2;
        A = sqrt(s * (s-l[0]) * (s-l[1]) * (s-l[2]));
        cout << "面積 = " << A << "\n";

        for(int i=0;i<3;i++) l[i] *= l[i];
        if(l[0] + l[1] < l[2]) cout << "鈍角三角形\n";
        else if(l[0] + l[1] == l[2]) cout << "直角三角形\n";
        else cout << "鋭角三角形\n";
    }
    return 0;
}