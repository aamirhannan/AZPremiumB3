#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int>nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < n; i++)
	{
		mp[nums[i]].push_back(i + 1);
	}

	while (q--)
	{
		int a;
		cin >> a;

		vector<int>ans = mp[a];
		for (auto i : ans) {
			cout << i << " ";
		}
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

	int tc;
	cin >> tc;
	while (tc--)
	{
		solve();
	}
}
