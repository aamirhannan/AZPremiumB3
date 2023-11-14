#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

/*
Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 */

// int integerBreak(int n)
// {
// 	// 3*(n % 3) + n % 3;

// 	int x = n / 3;
// 	int ans = pow(3, x);
// 	ans *= n % 3;
// 	// ans *=  3;

// 	return ans;

// }

int integerBreak(int n)
{
	if (n <= 2) {
		return 1;
	}
	if (n == 3) {
		return 2;
	}

	if (n - 3 >= 2) {
		return 3 * integerBreak(n - 3);
	} else if (n - 3 < 2 and n - 3 > 0) {
		return n * integerBreak(n - n);
	}
}

void solve()
{

	int n;
	cin >> n;
	cout << integerBreak(n) << endl;




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
