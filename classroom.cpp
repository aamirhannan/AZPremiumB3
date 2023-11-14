#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(int x, vector<int>&nums, int k)
{
	int new_seat_assigned = 1;
	int prev_seat_left = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] <= prev_seat_left) {
			prev_seat_left -= nums[i];
		}
		else {
			new_seat_assigned++;
			prev_seat_left = x;
			if (nums[i] <= prev_seat_left) {
				prev_seat_left -= nums[i];
			}
			else {
				return 0;
			}
		}
	}

	return new_seat_assigned <= k;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int>nums(n);
	int sum = 0;
	for (int i = 0 ; i < n; i++)
	{
		cin >> nums[i];
		sum += nums[i];
	}

	int l = 1;
	int h = nums[n - 1] - nums[0];
	int ans = -1;

	sort(nums.begin(), nums.end());

	while ( l <= h)
	{
		int mid = l + (h - l) / 2;
		if (check(mid, nums, k)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			h = mid - 1;
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
