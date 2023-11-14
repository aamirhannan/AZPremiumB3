#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void even(int n)
{
	int x = sqrt(n);
	if (x * x == n) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

void odd(int n)
{
	int x = cbrt(n);
	if (x * x * x  == n) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

void solve()
{

	int a, n;
	cin >> a >> n;
	if (a == 1) even(n);
	else
		odd(n);
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
