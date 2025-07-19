#include "testlib.h"
#include <bits/stdc++.h>

const int MAXNP = 10;
const int MAXM = 100;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int group = validator.group()[0] - '0';

    int n = inf.readInt(1, MAXNP, "n");
    inf.readSpace();
    int m = inf.readInt(1, MAXM, "m");
    inf.readSpace();
    int p = inf.readInt(1, MAXNP, "p");
    inf.readEoln();

    std::set<std::string> names;

    for (int i = 0; i < n; i++) {
        // only lower case
        std::string name = inf.readToken(format("[a-z]{1,10}", "name"));
        ensure(names.count(name) == 0);
        names.insert(name);
        inf.readEoln();
    }

    for (int i = 0; i < m; i++) {
        std::string name, result;
        int problem;

        name = inf.readToken(format("[a-z]{1,10}", "name"));
        if (name == "view") {
            inf.readEoln();
            continue;
        }

        inf.readSpace();
        problem = inf.readInt(1, p, "problem");
        inf.readSpace();
        result = inf.readToken(format("[A-Z]{1,10}", "result"));
        inf.readEoln();

        ensure(names.count(name));

        if (group == 1) {
            ensure(result == "WA" || result == "TLE" || result == "MLE");
        }
        else {
            ensure(result == "AC" || result == "WA" || result == "TLE" || result == "MLE");
        }
    }
    
   
    inf.readEof();
}