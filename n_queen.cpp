#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n;
vector<int>queens;
int cnt = 0;
vector<vector<int>>ans;

bool check(int row, int col)
{
	for (int prow = 0; prow < row; prow++)
	{
		int pcol = queens[prow];
		if (pcol == col || abs(row - prow) == abs(col - pcol)) {
			return 0;
		}
	}

	return 1;
}


void rec(int level)
{
	//base case
	if (level == n)
	{
		ans.push_back(queens);
		cnt++;
		return;
	}

	//choices
	for (int col = 0; col < n; col++)
	{
		if (check(level, col))
		{
			//put
			queens.push_back(col);
			//call next
			rec(level + 1);
			//pop_back
			queens.pop_back();
		}
	}
}

void solve()
{
	cin >> n;
	rec(0);
	cout << cnt << endl;
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
