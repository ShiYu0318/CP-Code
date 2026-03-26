#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// gen N M

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int maxSize = atoi(argv[1]);
    int N = rnd.next(maxSize-10, maxSize);
    int M = rnd.next(maxSize-10, maxSize);
    int minVal = -1000;
    int maxVal = 1000;

    cout << N << " " << M << '\n';
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            int val = rnd.next(minVal, maxVal);
            cout << val << (j + 1 == M ? '\n' : ' ');
        }
    }
    return 0;
}
