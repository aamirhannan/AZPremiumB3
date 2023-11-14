#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(int x, vector<int>&nums, int k)
{
	int needed = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		needed += (((nums[i] - nums[i - 1]) - 1) / x);
	}

	return needed <= k;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());
	int l = 1;
	int h = 0;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		h = max(h, nums[i] - nums[i - 1]);
	}

	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (check(mid, nums, k))
		{
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

	int tc;
	cin >> tc;
	while (tc--)
	{
		solve();
	}
}
