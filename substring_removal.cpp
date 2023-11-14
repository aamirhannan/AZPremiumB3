#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

	stack<char> st;
	string s;
	int x, y;
	cin >> s >> x >> y;

	string o = "ab";
	string p = "ba";

	if (y > x) {
		swap(x, y);
		swap(o, p);
	}

	int ans = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (!st.empty() and st.top() == o[0] and s[i] == o[1]) {
			st.pop();
			ans += x;
		}
		else {
			st.push(s[i]);
		}
	}

	string m;
	while (!st.empty()) {
		m += st.top();
		st.pop();
	}

	reverse(m.begin(), m.end());

	for (int i = 0; i < m.size(); i++)
	{
		if (!st.empty() and st.top() == p[0] and m[i] == p[1]) {
			st.pop();
			ans  += y;
		}
		else {
			st.push(m[i]);
		}
	}

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
