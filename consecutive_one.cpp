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
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int head = -1, tail = 0, ans = 0, cnt = 0;
	while (tail < n) {

		//eat as much you can
		while (head + 1 < n and (cnt < k or arr[head + 1] == 1))
		{
			head++;
			if (arr[head] == 0) {
				cnt++;
			}
		}

		//register the answer
		ans = max(ans, head - tail + 1);

		//move tail
		if (head >= tail)
		{
			if (arr[tail] == 0) {
				cnt--;
			}
			tail++;
		}
		else {
			tail++;
			head = tail - 1;
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
