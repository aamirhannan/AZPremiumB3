#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
vector<int> arr;
int ans = INT_MAX;

int findMin(int level, int curSum)
{
	//base case
	if (level == n)
	{
		return ;
	}

	//take
	int take = arr[level] + findMin(level + 1, curSum)
	           //notTake
	           int notTake = findMin(level + 1, curSum)



}

void solve()
{
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	findMin(0, 0);
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
