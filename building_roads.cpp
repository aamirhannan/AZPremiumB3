#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
vector<vector<int>> g;
vector<int>vis;

void dfs(int node) {
	vis[node] = 1;
	for (auto v : g[node]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

void bfs(int node) {

	queue<int>q;
	vis[node] = 1;
	q.push(node);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto v : g[node]) {
			if (!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}


void solve()
{
	cin >> n >> m;
	g.resize(n + 1);
	vis.resize(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int component = 0;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			component++;
			bfs(i);
		}
	}

	cout << component - 1 << endl;


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
