#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m , k;
vector<int>arr, brr;


bool check(int x) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += upper_bound(brr.begin(), brr.end(), x - arr[i]) - brr.begin();
	}

	return cnt >= k;
}

void solve() {

//Input section
	cin >> n >> m >> k;
	arr.resize(n);
	brr.resize(m);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> brr[i];
	}

// Make sure n is always small
	if (n > m) {
		swap(n, m);
		swap(arr, brr);
	}

// sorted array is required for binary search
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());

// declaration of l, h, ans accordangly

	int l = arr[0] + brr[0];
	int h = arr.back() + brr.back();
	int ans = h; //we will surely get a true value so it dosn't matter what we get

	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (check(mid))
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

	int tc;
	cin >> tc;
	while (tc--)
	{
		solve();
	}
}
