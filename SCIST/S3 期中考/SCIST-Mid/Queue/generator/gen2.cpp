#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int options [] = {1, 1, 3, 3, 5};

signed main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    const int MAXN = 1000;
    const int MAXX = atoi(argv[2]);
    int n;
    
    if (rnd.next(0, 1))
        n = rnd.next(1LL, MAXN);
    else
        n = MAXN;
    
    cout << n << endl;

    int len = 0;

    for (int i = 0; i < n; i++) {
        int option, x;
        char c;

        if (len == 0)
            option = rnd.next(0, 1);
        else
            option = rnd.next(0, 4);

        if (i == n - 1 && len)
            option = 4;

        if (option < 2) {
            x = rnd.next(1LL, MAXX);
            c = rnd.next('a', 'z');
            len += x;
            cout << options[option] << ' ' << x << ' ' << c << endl;
        }
        else if (option < 4) {
            x = rnd.next(1LL, min(len, MAXX));
            len -= x;
            cout << options[option] << ' ' << x << endl;
        }
        else {
            cout << options[option] << endl;
        }
    }

    
    return 0;
}