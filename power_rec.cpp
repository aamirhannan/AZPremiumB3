#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


//Approach -1
int rec1(int x, int n)
{
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= x;
	}

	return ans;
}


//Approach - 2
int rec2(int x, int n) {
	if (n == 0)	return 1;
	if (x == 0)	return 0;

	return x * rec2(x, n - 1);
}

//Approach - 3
int rec3(int x, int n)
{
	if (n == 0)	return 1;

	int ans = rec3(x, n / 2);
	if (n % 2 == 0)	return ans * ans;
	else
		return x * ans * ans;
}

void solve()
{
	int x, n;
	cin >> x >> n;

	cout << "First Call " << rec1(x, n) << endl;
	cout << "Second Call " << rec2(x, n) << endl;
	cout << "Third Section " << rec3(x, n) << endl;
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
