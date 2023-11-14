#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, cnt;
vector<string> board;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool check(int i, int j)
{
	if (board[i][j] == 'Q')	return 0;
	for (int pos = 0; pos < 8; pos++)
	{
		int nx = i + dx[pos];
		int ny = j + dy[pos];

		if (nx < n && nx >= 0 && ny < n && ny >= 0 && board[nx][ny] == 'Q' )	return 0;
	}
	return 1;
}

bool isValid(int row, int col)
{
	int duprow = row;
	int dupcol = col;

	//diagonally upward
	while (row >= 0 and col >= 0)
	{
		if (board[row][col] == 'Q') return false;
		row--;
		col--;
	}

	row = duprow;
	col = dupcol;

	//backward
	while (col >= 0)
	{
		if (board[row][col] == 'Q') return false;
		col--;
	}

	row = duprow;
	col = dupcol;
	//diagonally downward
	while (row < n and col >= 0)
	{
		if (board[row][col] == 'Q') return false;
		row++;
		col--;
	}

	return true;
}

void rec(int level)
{
	if (level == n) {
		cnt++;
		return;
	}

	for (int row = 0; row < n; row++)
	{
		if (isValid(row, level) and check(row, level))
		{
			board[row][level] = 'Q';
			rec(level + 1);
			board[row][level] = '.';
		}
	}
}


void solve()
{
	cin >> n;
	cnt = 0;
	board.resize(n);
	string s(n, '.');
	for (int i = 0; i < n; i++) {
		board[i] = s;
	}

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