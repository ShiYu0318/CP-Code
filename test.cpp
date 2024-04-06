#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 如何輸出一串數字用空格分開並在最後換行

    // 方法一
    for(int i=0; i<n; ++i){
        cout << i << " ";
    }
    cout << "\n";

    // 方法二
    for(int i=0; i<n; ++i){
        cout << i << " \n"[i == n-1];
    }

}