#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int a[] = {1,2,3,4,5};

    // 原本的 for
    for(int i=0;i<5;i++) cin >> a[i]; 
    for(int i=0;i<5;i++) cout << a[i] << ' '; 
    
    // 新版本 可自動遍歷
    for(int &i : a) cin >> i;
    for(int i : a) cout << i << ' '; 
}