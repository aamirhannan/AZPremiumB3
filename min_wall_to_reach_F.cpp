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
vector<vector<char>> arr;
vector<vector<int>> dis;

bool isValid(int x, int y)
{
	if (x >= 0 and x < n and y >= 0 and y < m) {
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

void bfs01(state st_node) {
	dis.resize(n, vector<int>(m, INF));

	deque<state> dq;
	dq.push_front(st_node);
	dis[st_node.F][st_node.S] = 0;


	while (!dq.empty()) {
		state node = dq.front();
		dq.pop_front();
		for (auto v : neigbour(node)) {
			int edge_w = 0;
			if (arr[v.F][v.S] == '#') edge_w = 1;
			if (dis[v.F][v.S] > dis[node.F][node.S] + edge_w) {
				dis[v.F][v.S] = dis[node.F][node.S] + edge_w;
				if (edge_w = 0) {
					dq.push_front(v);
				}
				else {
					dq.push_back(v);
				}

			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	arr.resize(n);
	state st, en;
	for (int i = 0; i < n; ++i)
	{
		arr[i].resize(m, 0);
		for (int j = 0;  j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				st = {i, j};
			}
			else if (arr[i][j] == 'F') {
				en = {i, j};
			}
		}
	}

	bfs01(st);

	cout << dis[en.F][en.S] << endl;




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
