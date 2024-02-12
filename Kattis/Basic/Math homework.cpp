#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b,d,c,l,t,s,n=0;
    bool impossible = true;
    cin >> b >> d >> c >> l;
    for(int i=0;i <= l/b;i++)
    {
        for(int j=0;j <= l-b*i;j++)
        {
            for(int k=0;k <= l-b*i-d*j;k++)
            {
            	s = b*i + d*j + c*k;
            	if(s>l) break;
            	else if(s==l)
            	{
            		impossible = false;
            		cout << i << " " << j << " " << k << "\n";
            	}
            }
        }
    }
    if(impossible == true) cout << "impossible\n";
}