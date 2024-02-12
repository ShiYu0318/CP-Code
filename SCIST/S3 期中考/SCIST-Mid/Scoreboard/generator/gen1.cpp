#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const string res[] = {"WA", "TLE", "MLE"};

set<string> names;
vector<string> names_vec;

string gen_str() {
    string res;
    while (res.empty() || names.count(res) || res == "view") {
        res = "";
        for (int i = 0; i < 8; i++)
            res += rnd.next("[a-z]");
    }
    return res;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    const int MAXN = 10;
    const int MAXM = 100;
    const int MAXP = 10;

    int n, m, p;
    if (rnd.next(0, 1))
        n = rnd.next(1, MAXN);
    else
        n = MAXN;
    
    m = MAXM;

    if (rnd.next(0, 1))
        p = rnd.next(1, MAXP);
    else
        p = MAXP;

    cout << n << ' ' << m << ' ' << p << endl;

    for (int i = 0; i < n; i++) {
        string name = gen_str();
        names.insert(name);
        names_vec.push_back(name);

        cout << name << endl;
    }

    for (int i = 0; i < m; i++) {
        if (rnd.next(0, 2) % 3 == 0) {
            cout << "view" << endl;
        }
        else {
            int index = rnd.next(0, (int)names_vec.size() - 1);
            cout << names_vec[index] << ' ' << rnd.next(1, p) << ' ' << res[rnd.next(0, 2)] << endl;
        }
    }

    return 0;
}