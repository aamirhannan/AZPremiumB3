#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// bool isPrime(int n) {
// 	if (n <= 1) return false;
// 	if (n <= 3) return true;
// 	if (n % 2 == 0 || n % 3 == 0) return false;

// 	for (int i = 5; i * i <= n; i += 6) {
// 		if (n % i == 0 || n % (i + 2) == 0) return false;
// 	}

// 	return true;
// }

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)	return 0;
	}
	return 1;
}

void solve() {
	int n;
	cin >> n;

	if (isPrime(n)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;

	while (tc--) {
		solve();
	}
}
