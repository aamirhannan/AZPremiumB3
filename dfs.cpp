#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
vector<vector<int>> g;
vector<int> vis;

bool is_cyclic = false;

void dfs(int node, int parent) {
	vis[node] = 1;
	for (auto v : g[node]) {
		if (!vis[v]) {
			dfs(v, node);
		} else if (v != parent) {
			is_cyclic = true;
		}
	}
}


void solve()
{
	cin >> n >> m;
	g.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);

		//if undirected
		g[b].push_back(a);
	}
	vis.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0);
		}
	}

	cout << is_cyclic << endl;
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
