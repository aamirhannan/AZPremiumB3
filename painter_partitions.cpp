#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int check(int x, vector<int>&nums, int n, int k)
{
	int new_painter_spwaned = 0;
	int last_painter_time_left = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] <= last_painter_time_left) {
			last_painter_time_left -= nums[i];
		}
		else {
			new_painter_spwaned++;
			last_painter_time_left = x;
			if (nums[i] <= last_painter_time_left) {
				last_painter_time_left -= nums[i];
			}
			else {
				return 0;
			}

		}
	}

	return new_painter_spwaned <= k ? 1 : 0;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	int sum = 0;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		sum += nums[i];
	}

	int l = 1, h = sum, ans = -1;
	while (l <= h)
	{
		int mid = l + ((h - l) / 2);
		if (check(mid, nums, n, k))
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
