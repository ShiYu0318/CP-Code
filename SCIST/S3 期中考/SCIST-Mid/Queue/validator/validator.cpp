#include "testlib.h"
#include <bits/stdc++.h>

const int MAXN = 1000;
const int MAXX[] = {(int)1e9, 10, (int)1e9, 10, (int)1e9, (int)1e9};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int group = validator.group()[0] - '0';

    int n = inf.readInt(1, MAXN, "n");
    inf.readEoln();

    long long len = 0;

    for (int i = 0; i < n; i++) {
        int op = inf.readInt(1, 5, "op");

        if (op == 5)
            inf.readEoln();
        else
            inf.readSpace();

        // subtask 1, 2: op -> 2, 4, 5
        // subtask 3, 4: op -> 1, 3, 5
        // subtask 5: op -> 1, 2, 3, 4, 5

        if (group == 1 || group == 2)
            ensure(op == 2 || op == 4 || op == 5);
        else if (group == 3 || group == 4)
            ensure(op == 1 || op == 3 || op == 5);
        else
            ensure(op == 1 || op == 2 || op == 3 || op == 4 || op == 5);

        if (op == 5)
            continue;

        if (op == 1 || op == 2) {
            int x = inf.readInt(1, MAXX[group], "x");
            inf.readSpace();
            std::string c = inf.readToken(format("[a-z]{1}", x), "c");
            inf.readEoln();

            len += x;
        }
        else if (op == 3 || op == 4) {
            int x = inf.readInt(1, std::min((long long)MAXX[group], len), "x");
            inf.readEoln();
            len -= x;
        }

        ensure(len >= 0);
    }

    inf.readEof();
}