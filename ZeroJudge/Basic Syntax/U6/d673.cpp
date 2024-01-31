#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i

int main()
{
    int n,c=1; 
    while(cin >> n)
    {
        if(n < 0) return 0;
        cout << "Case " << c << ":\n"; ++c;
        vector<int> a(12),b(12);
        input(a); input(b);
        int sum = n;
        RPT(i,12)
        {
            if(b[i] <= sum)
            {
                cout << "No problem! :D\n";
                sum -= b[i]; 
            }
            else cout << "No problem. :(\n";
            sum += a[i];
        }
    }
}