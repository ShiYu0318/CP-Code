#include <bits/stdc++.h>
using namespace std;


int main()
{
    map<int,queue<int>> mq;
    mq[0].emplace(35);
    mq[1].emplace(10);
    mq[0].emplace(25);
    for (auto it = mq.begin(); it != mq.end(); ++it)
    {
        cout << it->second.front() << "\n";

    }
}