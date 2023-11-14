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
vector<state> g[100100];


int dis[100100];
int vis[100100];

void dijkstra(int sc) {
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[sc] = 0;
	priority_queue<state, vector<state>, greater<state>> pq;
	pq.push({0, sc});

	while (!pq.empty())
	{
		state node = pq.top();
		pq.pop();

		if (vis[node.S]) continue;
		vis[node.S] = 1;

		for (auto v : g[node.S])
		{
			int neigh = v.F;
			int wt = v.S;
			if (dis[neigh] > dis[node.F] + wt) {
				dis[neigh] = dis[node.S] + wt;
				pq.push({dis[neigh], neigh});
			}
		}
	}

}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	dijkstra(1);

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
