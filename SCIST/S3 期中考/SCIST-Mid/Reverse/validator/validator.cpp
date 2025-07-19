#include "testlib.h"
#include <bits/stdc++.h>

const int MAXN = 2000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int group = validator.group()[0] - '0';

    int n = inf.readInt(1, MAXN, "n");
    inf.readEoln();
    bool first = true;
    std::stack<char> stk;

    std::stringstream ss;
    std::string Line = inf.readLine();
    ss << Line;

    std::string s;

    while (ss >> s) {
        if (first) {
            first = false;
        }

        if (s == "[") {
            stk.push('[');
        }
        else if (s == "]") {
            ensure(!stk.empty() && stk.top() == '[');
            if (group == 1)
                ensure(stk.size() == 1);
            stk.pop();
        }
        n--;
    }

    ensure(stk.empty());
    ensure(n == 0);

    inf.readEof();
}