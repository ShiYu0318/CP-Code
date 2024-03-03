#include "testlib.h"
#include <bits/stdc++.h>

const int MAXN[] = {(int)2e5, (int)1e3, (int)1e4, (int)2e5};
const int MAXK[] = {(int)1e9, (int)1e4, (int)1e9, (int)1e9};
const int MAXA = (int)5e4;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int group = validator.group()[0] - '0';
    int n = inf.readInt(1, MAXN[group], "n");
    inf.readSpace();
    int k = inf.readInt(1, MAXK[group], "k");
    inf.readEoln();

    for (int i = 0, a; i < n; i++) {
        inf.readInt(1, MAXA, "a");
        if (i != n - 1)
            inf.readSpace();
        else
            inf.readEoln();
    }
    

    inf.readEof();
}