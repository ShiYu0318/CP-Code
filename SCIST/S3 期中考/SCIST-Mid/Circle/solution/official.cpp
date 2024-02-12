#include "iostream"
using namespace std;
#define int long long
int ary[400010]={};
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>ary[i];
    }
    int base=0;
    int cir=k/n;
    for(int i=1;i<=n;i++){
        int nxt=max((int)1,ary[i]-cir+1);
        base+=(ary[i]+nxt)*(ary[i]-nxt+1)/2;
        nxt--;
        ary[i]=nxt;
        ary[i+n]=nxt;
    }
    for(int i=1;i<=2*n;i++){
        ary[i]+=ary[i-1];
    }
    int ans=0;
    k-=cir*n;
    for(int i=1;i<=n;i++){
        ans=max(ans,ary[i+k]-ary[i]);
    }
    cout<<ans+base<<"\n";
}