#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int find_sum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int check(int x, int n, int s) {
	int digit_sum = find_sum(x);
	if (s <= (x - digit_sum) and x <= n) {
		return 1;
	}
	return 0;
}

void solve()
{

	int n, s;
	cin >> n >> s;

	int l = s, h = n, ans = n + 1;
	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (check(mid, n, s)) {
			ans = mid;
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	if (s == 0) {
		cout << n << endl;
	}
	else if (ans == 0) {
		cout << ans << endl;
	}
	else {
		cout << n - ans + 1 << endl;
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
