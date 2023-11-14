#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0, curr = v[0];

    for (int i = 1; i < n; i++)
    {
        if (v[i] < curr) {
            curr = v[i];
        }
        else if (v[i] - curr - k > 0) {
            ans += v[i] - curr - k;
            curr = v[i] - k;
        }
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

    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
