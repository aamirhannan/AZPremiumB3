#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool solve()
{
	string str1, str2;
	cin >> str1 >> str2;

	int n  = str1.size();
	int m  = str2.size();
	if (n < m) {
		return false;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tolower(str2[i]) == tolower(str1[j])) {
				cnt++;
				str1[j] = '0';
			}
		}
	}

	if (m == cnt) {
		return true;
	} else {
		return false;
	}
}

signed main()
{

	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int tc;
	// cin >> tc;
	// while (tc--)
	// {
	cout << solve();
	// }
}
