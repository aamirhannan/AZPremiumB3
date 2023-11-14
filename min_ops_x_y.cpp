#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int minOperation(int x, int y)
{
	if (x == y)	return 0;

	if (x <= 0 and y > 0)	return -1;

	if (x > y)	return x - y;

	if (y & 1)
		return 1 + minOperation(x, y + 1);
	else
		return 1 + minOperation(x, y / 2);
}

void solve()
{
	int x, y;
	cin >> x >> y;

	cout << minOperation(x, y);
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
	solve();
	// }
}
