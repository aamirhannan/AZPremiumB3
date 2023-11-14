#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
	return p1.second < p2.second;
}

void solve()
{

	vector<pair<int, int>> arr;
	int n;
	cin >> n;

	for (int i = 0; i < n ; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}


	sort(arr.begin(), arr.end(), cmp);

	int cnt = 0, prev = -1e9;

	for (auto it : arr)
	{

		int l = it.first;
		int r = it.second;

		if (l > prev) {
			prev = r;
			cnt++;
		}

	}
	cout << cnt << endl;
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
