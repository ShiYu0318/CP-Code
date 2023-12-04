#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<b; ++i)



int main(void)
{
    deque<int> dq;
    dq.emplace_back(1);
    dq.emplace_front(2);
    dq.emplace_back(4);
    dq.emplace_back(3);
    while(!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
}