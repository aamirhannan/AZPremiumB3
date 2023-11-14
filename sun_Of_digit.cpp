#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

	string n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		int x;
		stringstream ss;
		ss << n[i];
		ss >> x;
		sum += x;
	}
	cout << sum << endl;
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
