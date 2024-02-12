#include <bits/stdc++.h>
using namespace std;
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define yn(x) cout << (x ? "Yes" : "No") << "\n"

signed main()
{
    int A,B; cin >> A >> B;
    if(0 < A && B == 0) cout << "Gold\n";
    else if(0 == A && B > 0) cout << "Silver\n";
    else if(0 < A && 0 < B) cout << "Alloy\n";
}
