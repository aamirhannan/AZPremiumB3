#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n, k;
map<int, int> mp;
vector<int>cur_perm;
vector<vector<int>> final_ans;


void print(vector<vector<int>>&final_ans)
{

	vector<int> ans = final_ans[k - 1];
	for (auto i : ans) {
		cout << i << " ";
	}

}

void rec(int level)
{
	if (level == n) {
		final_ans.push_back(cur_perm);
		return;
	}

	for (auto v : mp) {
		if (v.second != 0) {
			mp[v.first]--;
			cur_perm.push_back(v.first);
			rec(level + 1);
			cur_perm.pop_back();
			mp[v.first]++;
		}
	}
}

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		mp[i]++;
	}

	rec(0);

	print(final_ans);

	return;
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
