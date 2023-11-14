#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
vector<vector<int>> g;
vector<int>vis;
int size_comp = 0;

void dfs(int node) {
	vis[node] = 1;
	size_comp++;
	for (auto v : g[node]) {
		if (!vis[v])
			dfs(v);
	}
}

void solve()
{

	cin >> n >> m;
	g.resize(n + 1);
	vis.resize(n + 1, 0);
	vector<int>allsize;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}



	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			allsize.push_back(size_comp);
			size_comp = 0;
		}
	}

	// for (auto i : allsize) {
	// 	cout << i << " ";
	// }
	// cout << endl;

	if (allsize.size() <= 1) {
		cout << "0" << endl;
	}
	else {
		int left = accumulate(allsize.begin(), allsize.end(), 0LL);
		left *= left;
		// cout << "left -" << left << endl;
		int right = 0;
		for (auto i : allsize) {
			right += i * i;
		}
		// cout << "right -" << right << endl;
		cout << (left - right) / 2;

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
