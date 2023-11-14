#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;

int rec(int level)
{
	//pruning
	if (level > n)	return 0;

	//base case
	if (level == n)
	{
		return 1;
	}

	//choices
	int ans = 0;
	for (int stairs = 1; stairs <= 3; stairs++)
	{
		//check
		if (level + stairs <= n)
		{
			//move
			int ways = rec(level + stairs);
			ans += ways;
		}
	}

	return ans;
}

void solve()
{
	cin >> n;
	cout << rec(1);
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
