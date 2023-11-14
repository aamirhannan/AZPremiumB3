#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, m;
vector<pair<int, int>> g[100100];
int dis[100100];
void BFS01(int sc) {

	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dis[i] = 1e9;
	}

	dis[sc] = 0;
	dq.push_back(sc);
	while (!dq.empty()) {
		int node = dq.front();
		dq.pop_front();

		for (auto v : g[node]) {
			int neigh = v.first;
			int weigh = v.second;
			if (dis[neigh] > dis[node] + weigh) {
				dis[neigh] = dis[node] + weigh;

				if (weigh == 0) {
					dq.push_front(neigh);
				} else {
					dq.push_back(neigh);
				}

			}
		}
	}
}


void solve()
{

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	int sc;
	cin >> sc;

	BFS01(sc);
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
