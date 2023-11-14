#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(int x, vector<int>&nums)
{
	if (nums[x] < nums[0])	return 1;
	else	return false;
}

void findMInIdx(vector<int>&nums)
{
	int l = 0, h = nums.size() - 1, ans = 0;
	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (check(mid, nums) == 1) {
			ans = nums[mid];
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans << endl;
}

void solve()
{

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	findMInIdx(nums);
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
