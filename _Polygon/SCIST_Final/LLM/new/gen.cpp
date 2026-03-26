#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) 
{
    registerGen(argc, argv, 1);

    int Q = rnd.next(30, 50);
    int sub = atoi(argv[1]);

    for (int i = 0; i < Q; ++i) 
    {
        int op = (sub == 4 ? rnd.next(1, 3) : sub); 
        cout << op << " ";

        if (op == 1) 
        {
            int m = rnd.next(1, 30);
            int in_t = rnd.next(10'0000, 1000'0000);
            int out_t = rnd.next(10'0000, 1000'0000);
            cout << m << " " << in_t << " " << out_t << '\n';
        } 
        else if (op == 2) 
        {
            int budget = rnd.next(10, 1000);
            int in_t = rnd.next(1000, 1000'0000);
            cout << budget << " " << in_t << '\n';
        } 
        else if (op == 3) 
        {
            int k = rnd.next(1, 30);
            cout << k << '\n';
        }
    }
    cout << 0 << '\n';
    return 0;
}

/*
<#list 1..4 as testNumber>
    gen 1 ${testNumber} > $
</#list>
<#list 5..10 as testNumber>
    gen 2 ${testNumber} > $
</#list>
<#list 11..16 as testNumber>
    gen 3 ${testNumber} > $
</#list>
<#list 17..20 as testNumber>
    gen 4 ${testNumber} > $
</#list>
*/