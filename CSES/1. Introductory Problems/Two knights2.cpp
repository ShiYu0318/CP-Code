#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n, i = 1;
    for (cin >> n; i <= n; ++i){
        cout << (i * i * (i * i - 1) >> 1) - ((i - 2) * (i - 1) << 2) << '\n';
    }
}