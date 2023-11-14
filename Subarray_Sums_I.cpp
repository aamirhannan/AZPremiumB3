#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

	int n, k;
	cin >> n >> k;
	vector<int>nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	int sum = 0, cnt = 0;

	int i = 0, j = 0;
	while (j < n)
	{
		if (sum == k) {
			cnt++;
			j++;
		}
		else if (sum > k) {
			sum -= nums[i];
			i++;
		}
		else {
			sum += nums[j];
			j++;
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

	// int tc;
	// cin >> tc;
	// while (tc--)
	// {
	solve();
	// }
}
