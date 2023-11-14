#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

	int n, target;
	cin >> n >> target;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0, j = n - 1;
	bool printed = false;
	while (i < j) {
		int sum = arr[i] + arr[j];
		if (sum == target) {
			cout << i << " " << j << endl;
			printed = true;
			i++;
			j--;
			break;

		}
		else if (sum > target) {
			j--;
		}
		else {
			i++;
		}
	}

	if (printed == false) {
		cout << "-1" << " " << -1 << endl;
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
