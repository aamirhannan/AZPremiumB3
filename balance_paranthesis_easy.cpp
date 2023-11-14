#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

string str = "";

void generate_paranthesis(int open, int close)
{
	if (open == 0 and close == 0) {
		cout << str << endl;
		return;
	}

	if (open > 0) {
		str += "(";
		generate_paranthesis(open - 1, close);
		str.pop_back();
	}

	if (close > open) {
		str += ")";
		generate_paranthesis(open, close - 1);
		str.pop_back();
	}
}

void solve()
{

	int n;
	cin >> n;
	int open = n / 2;
	int close = open;
	generate_paranthesis(open, close);
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
