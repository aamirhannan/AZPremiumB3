#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(int x, vector<int>&arr, int k)
{
	int new_painter_spwaned = 0;
	int last_painter_time_left = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] <= last_painter_time_left) {
			last_painter_time_left -= arr[i];
		}
		else {
			new_painter_spwaned++;
			last_painter_time_left = x;
			if (arr[i] <= last_painter_time_left) {
				last_painter_time_left -= arr[i];
			}
			else {
				return 0;
			}
		}
	}

	return new_painter_spwaned <= k ? true : false;
}


void solve()
{

	int n, k;
	cin >> n >> k;

	vector<int>arr(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	int l = 1;
	int h = sum;
	int ans = 0;


	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (check(mid, arr, k))
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

	// int tc;
	// cin >> tc;
	// while (tc--)
	// {
	solve();
	// }
}
