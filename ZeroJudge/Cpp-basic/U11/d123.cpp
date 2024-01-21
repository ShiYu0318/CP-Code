#include<bits/stdc++.h>
using namespace std;
#define input(x) for(auto &i : x) cin >> i
#define FOR(i,a,b) for(int i=a;i<b;++i) 
#define RPT(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()

int main()
{
	int n,c=1;
	while(cin >> n)
	{
        bool ans = true;
		vector<int> v(n); input(v);
		set<int> s;
        RPT(i,n-1)
        {
            FOR(j,i,n)
            {
                int t = v[i] + v[j];
                if(!s.empty() && s.find(t) != s.end())
                {
                    ans = false;
                    break;
                }
                s.insert(t);
            }
        }
        cout << "Case #" << c << ": It is ";
        if(!ans) cout << "not ";
        cout << "a B2-Sequence.\n\n";
        ++c;
	}
}