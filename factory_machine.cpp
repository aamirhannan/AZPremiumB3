#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int check(int x, vector<int>&nums, int n, int t)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += min((x / nums[i]), (int)1e9);
	}
	return ans >= t;
}

void solve()
{
	int n, t;
	cin >> n >> t;
	vector<int>nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int l = 1, h = 1e18, ans = 0;
	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (check(mid, nums, n, t)) {
			ans = mid;
			h = mid - 1;
		}
		else {
			l = mid + 1;
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

	// int tc;
	// cin >> tc;
	// while (tc--)
	// {
	solve();
	// }
}
