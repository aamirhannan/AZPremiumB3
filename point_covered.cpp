#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

	int q;
	cin >> q;
	unordered_set<int>st;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		for (int i = a; i <= b; i++)
		{
			st.insert(i);
		}
	}

	cout << st.size() << endl;


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
