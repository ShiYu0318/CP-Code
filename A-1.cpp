#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        vector<int> table;
        for(int j=0;j<x;j++)    table.push_back(j+1);
        deque<int> hand;
        for(int k=0;k<x;k++)
        {
            hand.push_front(table.back());
            table.pop_back();
            for(int l=0;l<hand.front()-1;l++)
            {
                hand.push_front(hand.back());
                hand.pop_back();
            cout << "hand\n";
            for(int m=0;m<hand.size();m++)  cout<<hand[m]<<" \n"[m==hand.size()-1];
            cout << "hand\n";
            for(int m=0;m<hand.size();m++)  cout<<hand[m]<<" \n"[m==hand.size()-1];
            }

        }
        cout<<hand.front();
        hand.pop_front();
        while(!hand.empty())
        {
            cout<<" "<<hand.front();
            hand.pop_front();
        }
        cout<<"\n";
    }
}