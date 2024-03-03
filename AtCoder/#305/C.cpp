#include<bits/stdc++.h>
#define int long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main()
{
	IO;
	int h,w,i,max=0,l,f,a,fl=-1;
	cin >> h >> w;
	string s[h];
	int n[h];
	for(i=0;i<h;i++) n[i]=0;
	for(i=0;i<h;i++) cin >> s[i];
	for(i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(s[i][j] == '#') n[i]++;
		}
		if(n[i] > max) max = n[i];
	}
	for(i=0;i<h;i++){
		if(fl == -1 && n[i] == max) fl = i;
	}
	for(i=0;i<h;i++){	
		if(n[i] == (max-1)){
			l = i;
			break;
		}
	}
	for(i=0;i<w;i++){
		if(s[fl][i] == '#'){
			f = i;
			break;
		}
	}
	for(i=f;i<f+max;i++){
		if(s[l][i] == '.'){
			a = i;
			break;
		}
	}
	cout << l+1 << " " << i+1 << "\n";
}