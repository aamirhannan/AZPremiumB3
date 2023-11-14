#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


void solve()
{
	int x, y;
	cin >> x >> y;
	int ans = 0;
	while (y > x)
	{
		if (y & 1) {
			y += 1;
			ans++;
		}
		else {
			y = y / 2;
			ans++;
		}
	}

	ans += (x - y);

	cout << ans << endl;
}

signed main()
{

	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	while (tc--)
	{
		solve();
	}
}
