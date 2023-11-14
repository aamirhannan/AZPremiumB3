#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;



bool check(int x, vector<int>&nums, int k)
{
	int new_subarray_spawned = 0;
	int last_subarray_left = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] <= last_subarray_left) {
			last_subarray_left -= nums[i];
		}
		else {
			new_subarray_spawned++;
			last_subarray_left = x;
			if (nums[i] <= last_subarray_left) {
				last_subarray_left -= nums[i];
			}
			else {
				return 0;
			}
		}
	}

	return new_subarray_spawned <= k ? 1 : 0;
}

void solve()
{

	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		sum += nums[i];
	}

	int l = 1, h = sum, ans = 0;

	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (check(mid, nums, k)) {
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
