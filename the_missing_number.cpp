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
	vector<int>first_array(n);
	int first_sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> first_array[i];
		first_sum += first_array[i];
	}
	vector<int>second_array(n - 1);
	int second_sum = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> second_array[i];
		second_sum += second_array[i];
	}
	vector<int>third_array(n - 2);
	int third_sum = 0;
	for (int i = 0; i < n - 2; i++) {
		cin >> third_array[i];
		third_sum += third_array[i];
	}

	cout << first_sum - second_sum << " " << second_sum - third_sum << endl;



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
