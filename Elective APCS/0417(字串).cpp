#include<bits/stdc++.h>
using namespace std;
/*
4/17
113 29 黃士育
while 亂數
*/
signed main()
{
    srand(time(NULL));
    char try_again = 'y';
    while(try_again == 'Y' || try_again == 'y')
    {
        for(int i=1;i<=29;i++)
        {
            cout << i << "號成績：" << rand()%100 << "\n";
        }
        cout << "try_again? (y/n):";
        cin >> try_again;
    }
}