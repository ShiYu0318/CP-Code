// DSU + 紀錄數量 + 路徑壓縮 + 啟發式合併

vector<int> boss, cnt;

int Find(int x)
{
    return (boss[x] == x ? x : boss[x] = Find(boss[x]));
}

void Join(int x, int y)
{
    int a = Find(x), b = Find(y);
    if(a == b) return;
    if(cnt[a] < cnt[b]) swap(a,b);
    cnt[a] += cnt[b];
    boss[b] = a;
}

signed main()
{
    ShiYu;
    int n,m,x,y; cin >> n >> m;
    boss.resize(n); cnt.resize(n,1); iota(all(boss),0);
    while(m--)
    {
        cin >> x >> y;
        Join(x,y);
    }
    cout << cnt[Find(0)] << '\n';
}