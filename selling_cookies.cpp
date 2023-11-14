#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{
	int n, ans = 0;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans += arr[i];
	}

	sort(arr.begin(), arr.end());

	ans -= arr[n - 1];

	if (arr[n - 1] >= ans) {
		ans =  arr[n - 1] - ans;
	}
	else {
		ans = (ans - arr[n - 1]) % 2;
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
