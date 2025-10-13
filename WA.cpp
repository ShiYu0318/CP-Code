#include <iostream>
using namespace std;

int main()
{
    int s,n,t,m,r,a[15][105],b[15][105],as,c=0,d,e=9999999,v;
    cin>>s>>t>>n>>m>>r;
    for(int i=0;i<s;i++){
        for(int j=0;j<t;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n-s+1;i++){
        for(int j=0;j<m-t;j++){
            as=0;
            d=0;
            v=0;
            for(int k=0;k<s;k++){
               for(int u=0;u<t;u++){
                   if(a[k][u]!=b[k+i][u+j]){ 
                   as++;
                   }
                   v+=a[k][u];
                   d+=b[k+i][u+j];
               }
            }
            if(as<=r) 
            {
                e=min(abs(v-d),e);
                c++;
            }
        }
    }
    cout<<c<<'\n';
    if(c==0) cout<<"-1\n";
    else cout<<e<<'\n';
    return 0;
}