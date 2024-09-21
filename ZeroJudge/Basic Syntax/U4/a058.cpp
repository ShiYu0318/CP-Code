// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int n, t, i, m[3] = {0};
// 	cin >> n;
// 	for(i = 0; i < n; i++)
// 	{
// 		cin >> t;
// 		if (t % 3 == 0) m[0]++;
// 		else if (t % 3 == 1) m[1]++;
// 		else m[2]++;
// 	}
// 	for(i = 0; i < 3; i++) cout << m[i] << ' ';
// 	cout << '\n';
// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int n; cin >> n;
// 	int a = 0, b = 0, c = 0, t;
// 	while(n--)
// 	{
// 		cin >> t;
// 		if (t % 3 == 0) a++;
// 		else if (t % 3 == 1) b++;
// 		else c++;
// 	}
// 	cout << a << ' ' << b << ' ' << c << '\n';
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	int a = 0, b = 0, c = 0, t;
	while(n--)
	{
		cin >> t;
		switch(t % 3)
		{
			case 0:
				a++;
				break;
			case 1:
				b++;
				break;
			case 2:
				c++;
				break;
		}
	}
	cout << a << ' ' << b << ' ' << c << '\n';
	return 0;
}