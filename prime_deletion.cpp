#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

	string s;
	cin >> s;

	bool foundOne = false;
	bool foundThree = false;
	for (int i = 0; i < 9; i++)
	{
		if (s[i] == '1' and foundThree == false) {
			cout << "13" << endl;
			break;
		}
		else if (s[i] == '3' and foundOne == false) {
			cout << "31" << endl;
			break;
		}
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
