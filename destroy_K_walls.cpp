#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

using state = pair<pair<int, int>, int>;
#define F first
#define S second


int n, m, k;
vector<vector<char>> arr;
vector<vector<vector<int>>> dis;

bool isValid(int x, int y)
{
	if (x >= 0 and x < n and y >= 0 and y < m) {
		return 1;
	}
	return 0;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<state> neighbour(state node)
{
	vector<state> neight;
	for (int i = 0; i < 4; i++)
	{
		int x = node.F.F + dx[i];
		int y = node.F.S + dy[i];
		if (isValid(x, y)) {
			int z = node.S;
			if (arr[x][y] == '#') z += 1;
			if (z > k)	continue;
			neight.push_back({{x, y}, z});
		}
	}
	return neight;
}

void bfs(state st_node)
{
	dis.assign(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
	queue<state>q;
	q.push(st_node);
	dis[st_node.F.F][st_node.F.S][st_node.S] = 0;
	while (!q.empty()) {
		state node = q.front();
		q.pop();

		for (auto v : neighbour(node))
		{
			if (dis[v.F.F][v.F.S][v.S] == INF) {
				dis[v.F.F][v.F.S][v.S] = dis[node.F.F][node.F.S][node.S] + 1;
				q.push(v);
			}

		}
	}
}
void solve()
{
	cin >> n >> m >> k;
	arr.resize(n);
	pair<int, int> st;
	pair<int, int> en;
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

	bfs({st, 0});

	int ans = INF;
	for (int bomb = 0; bomb <= k; bomb++) {
		ans = min(ans, dis[en.F][en.S][bomb]);
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
