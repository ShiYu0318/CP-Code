#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 100000;
const int MAXQ = 200000;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    string g1,g2,key="ATCGATCG";
    int leng = MAXN-9;
    int ll = leng;
    while(leng--){
        int n=rnd.next(0,3);
        g1+=key[n];
        if(rnd.next(0,50000)==1234){
            g2+=key[rnd.next(0,3)];
        }
        else{
            g2+=key[n];
        }
    }
    cout<<g1<<"\n"<<g2<<"\n";
    int q = MAXQ-5;
    cout<<q<<"\n";
    while(q--){
        int l = rnd.next(1,ll-90000);
        int r = rnd.next(ll-200,ll);
        cout<<l<<" "<<r<<"\n";
    }
    return 0;
}