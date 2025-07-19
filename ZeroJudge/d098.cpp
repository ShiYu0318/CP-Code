#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;++i)
using namespace std;

signed main()
{
    string s,tmp;
    while(getline(cin,s))
    {
        stringstream ss;
        ss.str(s);
        int sum = 0;
        while(ss >> tmp)
        {
            bool is_num = 1;
            FOR(i,0,tmp.size())
            {
                if(!('0' <= tmp[i] && tmp[i] <= '9'))
                {
                    is_num = 0;
                    break;
                }
            }
            if(is_num)
            {
                int p;
                stringstream to_num(tmp);
                to_num >> p;
                sum += p;
            }
        }
        cout << sum << '\n';

    }
}