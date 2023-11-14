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
vector<vector<int>> arr;
vector<vector<int>> vis;

bool isValid(int x, int y) {
	if (x >= 0 and x < n and y >= 0 and y < m and arr[x][y] != 1) {
		return 1;
	}
	return 0;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<state> neigbour(state node)
{
	vector<state> neighs;
	for (int i = 0; i < 4; i++)
	{
		int x = node.F + dx[i];
		int y = node.S + dy[i];
		if (isValid(x, y)) {
			neighs.push_back({x, y});
		}
	}

	return neighs;
}

void dfs(state st_node, int component) {

	vis.resize(n, vector<int>(m, -1));
	queue<state>q;
	q.push(st_node);
	vis[st_node.F][st_node.S] = component;
	while (!q.empty())
	{
		state node = q.front();
		q.pop();
		for (auto v : neigbour(node)) {
			if (!vis[v.F][v.S]) {
				vis[v.F][v.S] = component;
				q.push(v);
			}
		}

	}
}

void solve()
{
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int component = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			state st = {i, j};
			if (arr[i][j] == 0) {
				dfs(st, component);
				component++;
			}
		}
	}

	for (auto i : vis) {
		for (auto x : i) {
			cout << x << "\t \t";
		}
		cout << endl;
	}

	arr.clear();
	vis.clear();
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
