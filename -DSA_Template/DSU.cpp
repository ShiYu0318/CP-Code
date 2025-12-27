vector<int> boss;

int Find(int x)
{
    return (boss[x] == x ? x : boss[x] = Find(boss[x]));
}

void Join(int x, int y)
{
    int a = Find(x), b = Find(y);
    if(a != b) boss[b] = a;
}

signed main()
{
    ShiYu;
    int n,m,q,x,y; cin >> n >> m >> q;
    boss.resize(n+5); iota(all(boss), 0);
    while(m--)
    {
        cin >> x >> y;
        Join(x,y);
    }
    while(q--)
    {
        cin >> x >> y;
        cout << (Find(x) == Find(y) ? ":)" : ":(") << '\n';
    }
}