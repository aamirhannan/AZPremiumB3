#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

using state = pair<int, int>;
#define F first
#define S second

int n, m;
vector<string>arr;
vector<vector<int>> vis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y) {
	if (x >= 0 and x < n and y >= 0 and y < m and arr[x][y] == '.') {
		return 1;
	}
	return 0;
}

void dfs(state st_node)
{
	vis[st_node.F][st_node.S] = 1;
	for (int i = 0; i < 4; i++) {
		int x = st_node.F + dx[i];
		int y = st_node.S + dy[i];
		if (isvalid(x, y)) {
			if (!vis[x][y]) {
				dfs({x, y});
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	arr.resize(n + 1);
	vis.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] and arr[i][j] == '.') {
				ans++;
				state st = {i, j};
				dfs(st);
			}
		}
	}

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
