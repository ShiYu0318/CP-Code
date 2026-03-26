#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
const long double pin[] = { 5.00 , 0.15 , 0.05 , 5.00 , 0.15 , 1.25 , 0.25 , 0.05 , 1.25 , 1.25 , 60.00 , 1.10 , 120.00 , 3.00 , 3.00 , 15.00 , 1.25 , 1.25 , 3.50 , 7.00 , 0.27 , 0.27 , 0.20 , 5.00 , 3.00 , 0.30 , 3.00 , 0.55 , 0.55 , 0.07 };
const long double pout[] = { 15.00 , 0.60 , 0.20 , 15.00 , 0.60 , 10.00 , 2.00 , 0.40 , 10.00 , 10.00 , 240.00 , 4.40 , 480.00 , 15.00 , 15.00 , 75.00 , 2.50 , 5.00 , 10.50 , 21.00 , 0.81 , 0.85 , 0.80 , 15.00 , 15.00 , 0.50 , 15.00 , 2.19 , 2.19 , 0.14 };
const long double pqd[] = { 0.0112 , 0.0207 , 0.0239 , 0.0112 , 0.0207 , 0.0124 , 0.0172 , 0.0219 , 0.0124 , 0.0124 , 0.0030 , 0.0148 , 0.0010 , 0.0112 , 0.0112 , 0.0065 , 0.0165 , 0.0145 , 0.0123 , 0.0102 , 0.0198 , 0.0197 , 0.0199 , 0.0112 , 0.0112 , 0.0212 , 0.0112 , 0.0169 , 0.0169 , 0.0250 };
const string name[] = { "GPT-4.1" , "GPT-4.1-Mini" , "GPT-4.1-Nano" , "GPT-4o" , "GPT-4o-Mini" , "GPT-5" , "GPT-5-Mini" , "GPT-5-Nano" , "GPT-5-Pro" , "GPT-5-Thinking" , "o3" , "o3-mini" , "o3-Pro" , "Claude-3" , "Claude-3.5" , "Claude-4.1-Opus" , "Gemini-2" , "Gemini-2.5" , "Gemini-2.5-Pro" , "Gemini-2.5-Pro-Deep-Think" , "LLaMA-4-Scout" , "LLaMA-4-Maverick" , "Perplexity-Sonar" , "Grok-2" , "Grok-3" , "Grok-3-Mini" , "Grok-4" , "DeepSeek-R1" , "DeepSeek-R2" , "DeepSeek-V3" };
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int c; while(cin >> c, c) {
		// assert(c == 2);
		if(c == 1) {
			int n; long double tin, tout;
			cin >> n >> tin >> tout;
			n--;
			cout << fixed << setprecision(2) << (tin* pin[n] + tout * pout[n])/((long double) 1e6) << '\n';
		} else if(c == 2) {
			long double b, tin; cin >> b >> tin;
			long double mx = -87; string ans = name[0];
			for(int i = 0; i < 30; i++) {
				// int l = 0, r = 1e9;
				// while(l < r) {
					// int mid = (l+r+1)/2;
					// if((tin* pin[i] + mid * pout[i]) > b*((long double) 1e6)) r = mid-1;
					// else l = mid;
				// }
				long double tout = (b*1e6 - tin*pin[i])/pout[i];
				long double tef = tout * max((long double)0, (long double)1-pqd[i]*(tout/1e6));
				if(abs(tef-mx) <= 1e-6 && name[i] > ans) ans = name[i];
				else if(tef > mx) {
					mx = tef;
					ans = name[i];
				}
			}
			cout << ans << ' ' << fixed << setprecision(0) << mx << '\n';
		} else {
			int k; cin >> k;
			vector<pair<long double, string> > v;
			for(int i = 0; i < 30; i++) v.push_back({pin[i] + pout[i], name[i]});
			sort(v.begin(), v.end(), [&](const auto &A, const auto &B) {
				if(abs(A.first - B.first) <= 1e-6) return A.second > B.second;
				return A.first < B.first;
			});
			cout << v[k-1].second << ' ' << fixed << setprecision(2) << v[k-1].first << '\n';
		}
	}
	
}
