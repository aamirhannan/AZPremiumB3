#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int binary_search_rec(vector<int>&arr, int s, int e, int target) {

	if (s > e)	return -1;

	int mid = (s + e) / 2;

	if (arr[mid] == target) {
		return mid;
	}
	else if (arr[mid] > target) {
		return binary_search_rec(arr, s, mid - 1, target);
	}
	else if (arr[mid] < target) {
		return binary_search_rec(arr, mid + 1, e, target);
	}
}

void solve()
{
	int n, t;
	cin >> n >> t;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << binary_search_rec(arr, 0, n - 1, t);
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
