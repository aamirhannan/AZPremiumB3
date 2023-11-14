#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

	int n, bal;
	cin >> n >> bal;
	vector<int> v;
	for (int i = 0; i < n; i++ )
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (bal == 0 || bal < 0) {
			break;
		}
		if (v[i] <= bal) {
			ans++;
			bal  -= v[i];
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
