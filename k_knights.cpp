#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, k;
int ans;
int board[14][14];

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool check(int i, int j)
{
	if (board[i][j] == 1)	return 0;
	for (int pos = 0; pos < 8; pos++)
	{
		int nx = i + dx[pos];
		int ny = j + dy[pos];

		if ((nx < n && nx >= 0) && (ny < n && ny >= 0) && (board[nx][ny] == 1) )	return 0;
	}
	return 1;
}

// void rec(int level)
// {
// 	if (level == k) {
// 		ans++;
// 		return;
// 	}

// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < n; j++)
// 		{
// 			if (check(i, j))
// 			{
// 				board[i][j] = 1;
// 				rec(level + 1);
// 				board[i][j] = 0;
// 			}
// 		}
// 	}
// }


void rec2(int level, int knight)
{
	//base case
	if (level == n * n) {
		if (knight == 0) {
			ans++;
		}
		return;
	}

	int row = level / n;
	int col = level % n;

	//dont take
	rec2(level + 1, knight);

	//take
	if (knight > 0 and check(row, col))
	{
		board[row][col] = 1;
		rec2(level + 1, knight - 1);
		board[row][col] = 0;
	}
}


void solve()
{
	cin >> n >> k;
	ans = 0;
	// rec(0);

	// for (int i = 1; i <= k; i++) ans /= i;

	rec2(0, k);
	cout << ans << endl;
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



// <-------------------------------->
