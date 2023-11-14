#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


void decide(int i, int j)
{
	if ((i == j ) || (i + j == 8))	cout << '*';
	else cout << " ";
}

void print_row(int i)
{
	for (int j = 0; j < 26; j++)
	{
		decide(i, j);
	}
}

void solve()
{

	for (int i = 0; i < 10; i++) {
		print_row(i);
		cout << endl;
	}
}

signed main()
{

	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int tc; cin >> tc; while (tc--)
	solve();

}
