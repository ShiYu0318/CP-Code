// 建表
#include <bits/stdc++.h>
using namespace std;
#define FORn(i,n) for(int i=0;i<n;++i)

const int mx[] = {1,2,2,1,-1,-2,-2,-1},
        my[] = {2,1,-1,-2,-2,-1,1,2};

bool in_range(int x,int y)
{
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

signed main()
{
    string tb[5];
    FORn(i,5) cin >> tb[i];
    bool invalid;
    int kn = 0;
    FORn(i,5) 
    {
        FORn(j,5)
        {
            if(tb[i][j] == 'k')
            {
                kn++;
                invalid = false;
                FORn(k,8)
                {
                    int x = i + mx[k],y = j + my[k];
                    if(in_range(x,y) && tb[x][y] == 'k')
                    {
                        invalid = true;
                        break;
                    }
                }
            }
            if(invalid) break;
        }
        if(invalid) break;
    }
    cout << (invalid || kn != 9 ? "invalid" : "valid") << "\n";
}