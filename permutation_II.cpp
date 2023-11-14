/*

	{
		a = 0,
		b = 1,
		c = 2,
		d = 3,
		e = 4,
		f = 5,
		g = 6,
		h = 7,
		i = 8,
		j = 9
	}

	Task is to find a pair for a given 'n', where

		abcde
		------- = N
		fghij

*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve1()
{
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	do {
		int abcde = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4];
		int fghij = arr[0 + 5] * 10000 + arr[1 + 5] * 1000 + arr[2 + 5] * 100 + arr[3 + 5] * 10 + arr[4 + 5];
		if (abcde % fghij == 0) {
			cout << abcde << " " << fghij << " " << abcde / fghij << endl;
		}
	} while (next_permutation(arr.begin(), arr.end()));

}

void solve2()
{
	int n;
	cin >> n;
	for (int fghij = 1; fghij <= (99999 / n); fghij++)
	{
		int abcde = n * fghij;
		set<int> st;

		int temp = abcde;
		for (int i = 0; i < 5; i++)
		{
			st.insert(temp % 10);
			temp /= 10;
		}

		temp = fghij; // Use a temporary variable here
		for (int i = 0; i < 5; i++)
		{
			st.insert(temp % 10);
			temp /= 10;
		}

		if (st.size() == 10) {
			cout << abcde << " " << fghij << " " << abcde / fghij << endl;
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

	// int tc;
	// cin >> tc;
	// while (tc--)
	// {
	solve1();
	// }
}
