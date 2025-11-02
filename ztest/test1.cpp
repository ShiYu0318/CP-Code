#include <bits/stdc++.h>
using namespace std;


// a^(b/2) * a^(b/2) = a^b
long long f(long long a, long long b)
{
    if(b == 0) return 1;
    long long c = f(a, b/2);
    c *= c;
    if(b % 2 == 1) c *= a;
    return c;
}

int main()
{
    long long a,b;
    cin >> a >> b;
    cout << f(a,b) << "\n";
}