// 建表
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)

const string MONTH[] = {"Jan","Feb","Mar","Apr",
                        "May","Jun","Jul","Aug",
                        "Sep","Oct","Nov","Dec"},
             NAME[] = {"Capricorn","Aquarius","Pisces","Aries",
                        "Taurus","Gemini","Cancer","Leo",
                        "Virgo","libra","Scorpio","Sagittarius","Capricorn"};
const int NUM[] = {120,219,320,420,
                   520,621,722,822,
                   921,1022,1122,1221,9999};


int month_to_int(const string& s)
{
    FORn(i,12)
    {
        if(s == MONTH[i]) return i+1;
    }
    return -1;
}

signed main()
{
    int t; cin >> t;
    while(t--)
    {
        int d;
        string m;
        cin >> d >> m;
        int n = month_to_int(m) * 100 + d;
        int ans;
        for(ans=0; n > NUM[ans]; ++ans);
        cout << NAME[ans] << "\n";
    }

}