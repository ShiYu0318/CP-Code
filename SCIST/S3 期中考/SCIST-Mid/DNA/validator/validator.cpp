#include "testlib.h"
#include <bits/stdc++.h>

const int STRLEN[] = {(int)1e5, (int)1e5, (int)2e4, (int)1e5};
const int MAXQ[] = {(int)2e5, 100, (int)2e5, (int)2e5};
std::string code = "ATCG";

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int group = validator.group()[0] - '0';
    
    std::string s1, s2;
    s1 = inf.readToken();
    inf.readEoln();
    s2 = inf.readToken();
    inf.readEoln();

    ensure(s1.size() <= STRLEN[group]);
    ensure(s2.size() <= STRLEN[group]);
    ensure(s1.size() == s2.size());

    for (auto &it: s1) {
        ensure(it == code[0] || it == code[1] || it == code[2] || it == code[3]);
    }
    for (auto &it: s2) {
        ensure(it == code[0] || it == code[1] || it == code[2] || it == code[3]);
    }


    int q = inf.readInt(1, MAXQ[group], "q");
    inf.readEoln();

    while (q--) {
        int l = inf.readInt(1, s1.size(), "l");
        inf.readSpace();
        int r = inf.readInt(l, s1.size(), "r");
        inf.readEoln();
    }

    inf.readEof();
}