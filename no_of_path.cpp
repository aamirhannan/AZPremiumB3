#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

using state = pair<int, int>; // first - distance, second - No of ways
#define F first
#define S second

int n, m;
vector<vector<char>>arr;
vector<vector<int>> dis;
vector<vector<int>> num_path;

bool isValid(int x, int y)
{
	if (x >= 0 and x < n and y >= 0 and y < m and arr[x][y] != '#') {
		return 1;
	}
	return 0;
}


int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<state> neigbour(state node)
{
	vector<state>neigh;
	for (int i = 0; i < 4; i++) {
		int x = node.F + dx[i];
		int y = node.S + dy[i];
		if (isValid(x, y)) {
			neigh.push_back({x, y});
		}
	}
	return neigh;
}

void bfs(state st_node) {
	dis.resize(n, vector<int>(m, 100));
	num_path.resize(n, vector<int>(m, 0));

	queue<state>q;
	dis[st_node.F][st_node.S] = 0;
	num_path[st_node.F][st_node.S] = 1;
	q.push(st_node);

	while (!q.empty())
	{
		state node = q.front();
		q.pop();
		for (auto v : neigbour(node))
		{
			if (dis[v.F][v.S] == 100) {
				dis[v.F][v.S] = dis[node.F][node.S] + 1;
				num_path[v.F][v.S] = num_path[node.F][node.S];
				q.push(v);
			} else if (dis[v.F][v.S] == dis[node.F][node.S] + 1) {
				num_path[v.F][v.S] += num_path[node.F][node.S];
			}
		}

	}
}

void solve()
{

	cin >> n >> m;
	arr.resize(n);

	state st, en;

	for (int i = 0; i < n; i++) {
		arr[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				st = {i, j};
			} else if (arr[i][j] == 'F') {
				en = {i, j};
			}
		}
	}

	bfs(st);
	cout << num_path[en.F][en.S] << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dis[i][j] << "," << num_path[i][j] << "\t \t";
		}
		cout << endl;
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
	solve();
	// }
}
