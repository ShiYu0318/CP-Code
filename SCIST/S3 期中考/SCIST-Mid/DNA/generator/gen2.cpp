#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 20000;
const int MAXQ = 200000;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    string g1,g2,key="ATCGATCG";
    int leng = MAXN-4;
    int ll = leng;
    while(leng--){
        int n=rnd.next(0,3);
        g1+=key[n];
        if(rnd.next(0,175000)==0){
            g2+=key[rnd.next(0,3)];
        }
        else{
            g2+=key[n];
        }
    }
    cout<<g1<<'\n'<<g2<<'\n';
    int q = MAXQ-rnd.next(1,1000);
    cout<<q<<'\n';
    q-=170000;
    while(q--){
        int l = rnd.next(1,ll);
        int r = rnd.next(l,ll);
        cout<<l<<' '<<r<<'\n';
    }
    for(int i=0;i<170000;i++){
        int l = rnd.next(1,6000);
        int r = rnd.next(ll-1000,ll);
        cout<<l<<' '<<r<<'\n';
    }
    
    return 0;
}