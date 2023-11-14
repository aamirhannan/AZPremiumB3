#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int factorial(int n, vector<int>&fact)
{
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1] % MOD;
	}

	return fact[n];
}

int PnC(int n, int r, vector<int>&fact)
{
	// return factorial(n, fact) / (factorial(n - r, fact) * factorial(r, fact));

	cout << fact[n] << " " << fact[n - r] << " " << fact[r] << endl;
	return fact[n] / (1LL * fact[n - r] * fact[r]);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> fact(n + 1, 1);
	factorial(n, fact);
	cout << PnC(n, 15, fact);
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
