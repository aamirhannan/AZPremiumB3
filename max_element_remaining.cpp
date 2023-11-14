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
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
	int l = 0, h = n - 1;
	int prev_no = -1;
	while (l <= h) {
		int sum = vec[l] + vec[h];
		if (l == h) {
			prev_no = vec[l];
			break;
		}
		else if (sum < k) {
			if (prev_no > vec[l]) {
				prev_no = vec[l];
			}
			l++;
		}
		else if (sum > k) {
			if (prev_no < vec[h]) {
				prev_no = vec[h];
			}

			h--;
		}
		else {
			l++;
			h--;
		}
	}
	cout << prev_no << endl;
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
