#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> dis;

void bfs(int sr_node) {
	queue<int> q;

	vis[sr_node] = 1;
	dis[sr_node] = 0;
	q.push(sr_node);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto v : g[node]) {
			if (!vis[v]) {
				vis[v] = 1;
				dis[v] = dis[node] + 1;
				q.push(v);
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	g.resize(n + 1);
	vis.assign(n + 1, 0);
	dis.assign(n + 1, 1e9);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	bfs(1);
	for (int i = 1; i <= n; i++) {
		cout << i << ": " << vis[i] << ": " << dis[i] << endl;
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
