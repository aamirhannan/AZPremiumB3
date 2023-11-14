#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}


	sort(nums.begin(), nums.end());

	for (auto i : nums)
	{
		cout << i << " ";
	}
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
