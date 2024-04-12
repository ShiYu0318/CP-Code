#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl cout << "\n"
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define dbg(x) cout << #x << ' ' <<  x << "\n"

signed main()
{
    int t; cin >> t;
    string r,af,rnn = "null";
    int rn = 0;
    FOR(i,0,t)
    {
        string fs[100];
        int n; cin >> n;
        getline(cin,r); getline(cin,r);
        int hn = 0,l = 0;
        while(n--)
        {
            getline(cin,af);
            stringstream ss(af);
            while(ss >> fs[l]) 
            {
                l++;
            }
            ss.clear();ss.str("");
        }
        // FOR(i,0,l) dbg(fs[i]);nl;nl;
        FOR(i,0,l)
        {
            if((fs[i] == "pancakes") || (i != l-1 && (fs[i] == "pea" || fs[i] == "paa") && fs[i+1] == "soup")) hn++;
        }
        if(hn == 2)
        {
            rn++;
            if(rnn == "null") rnn = r;
        }
        // dbg(hn);dbg(rnn);
    }
    // dbg(rn);
    if(rn == t) cout << "Anywhere is fine I guess\n";
    else cout << rnn << "\n";
}