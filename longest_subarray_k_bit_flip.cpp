// 1 1 1 0 1 0 0 1 0 1 0 1 0 1 - K = 3, find longest subarray having 3 zero's;


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
	vector<int> nums(n);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	int head = -1, tail = 0, ans = 0, cnt = 0;

	while (tail < n) {

		//eat as much as u can
		while (head + 1 < n and (cnt < k or nums[head + 1] == 1)) {
			head++;
			if (nums[head] == 0) {
				cnt++;
			}
		}

		//register the length
		ans = max(ans, head - tail + 1);

		//move the tail
		if (head >= tail) {
			if (nums[tail] == 0)	cnt--;
			tail++;
		}
		else {
			tail++;
			head = tail - 1;
		}
	}
	cout <<  (n * (n - 1)) / 2 -  ans << endl;
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
