#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


int cnt = 0;

bool isValid(int row, int col, vector<string> &board, int n)
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


void recursion(int col, int n, vector<string>&board, vector<vector<string>> &ans)
{
	if (col == n)
	{
		cnt++;
		// ans.push_back(board);
		return;
	}

	for (int row = 0; row < n; row++)
	{
		if (isValid(row, col, board, n) and board[row][col] != '*')
		{
			board[row][col] = 'Q';
			recursion(col + 1, n, board, ans);
			board[row][col] = '.';
		}
	}
}

void solve()
{
	int n = 8;
	vector<vector<string>> ans;
	vector<string> board(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		board[i] = s;
	}


	recursion(0, n, board, ans);
	cout << cnt << endl;
	// for (auto vec : ans) {
	// 	for (auto i : vec) {
	// 		cout << i << endl;
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
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
