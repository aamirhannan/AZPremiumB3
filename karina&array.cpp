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
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	if (n == 2)
	{
		cout << arr[0]*arr[1] << endl;
	}
	else if (n == 3)
	{
		int nums1 = arr[0] * arr[1];
		int nums2 = arr[1] * arr[2];

		cout << max(nums1, nums2) << endl;
	}
	else {

		int nums1 = arr[0] * arr[1];
		int nums2 = arr[n - 1] * arr[n - 2];

		cout << max(nums1, nums2) << endl;
	}

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
