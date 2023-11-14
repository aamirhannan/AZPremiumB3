#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
vector<vector<int>> g;
vector<int> vis;

bool is_bipartite = true;

void dfs(int node, int color) {
	vis[node] = color;
	for (auto v : g[node]) {
		if (!vis[v]) {
			dfs(v, 3 - color);
		}
		else if (vis[v] == vis[node]) {
			is_bipartite = false;
		}
	}
}

void solve()
{
	cin >> n >> m;
	g.resize(n + 1);
	vis.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 1);
		}
	}

	if (is_bipartite == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
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
