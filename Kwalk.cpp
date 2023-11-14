#include <bits/stdc++.h>
using namespace std;

using state = pair<int, int>;
#define F first
#define S second


int n;
state st, en;
vector<vector<int>> dis;


bool isValid(int x, int y) {
	if (x >= 1 and x <= n and y >= 1 and y <= n and dis[x][y] == 1e9) {
		return true;
	}
	else {
		return false;
	}
}

int dx[] = {2,  1, -1, -2, -2, -1, 1, 2};
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1};

void bfs(state st) {


	dis.clear();
	dis.resize(n + 1, vector<int>(n + 1, 1e9));

	queue<state> q;
	dis[st.F][st.S] = 0;
	q.push(st);

	while (!q.empty()) {
		state node = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int x = node.F + dx[i];
			int y = node.S + dy[i];
			if (isValid(x, y)) {
				dis[x][y] = dis[node.F][node.S] + 1;
				q.push({x, y});
			}
		}
	}
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
	n = N;
	st = {Sx, Sy};
	en = {Fx, Fy};
	bfs(st);


	if (dis[en.F][en.S] == 1e9) {
		return -1;
	}
	return dis[en.F][en.S];
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}