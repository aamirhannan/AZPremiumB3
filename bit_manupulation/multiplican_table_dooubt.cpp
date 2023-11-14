#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(int x, int n, int k)
{
    int prev_no = 0;
    for (int i = 1; i <= n; i++)
    {
        prev_no += min(n, x / i);
    }

    return (prev_no >= k) ? true : false;
}

void solve()
{
    int n;
    cin >> n;
    int l = 1, h = n * n, k = (h / 2) + 1, ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(mid, n, k))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int tc; cin >> tc;
    // while (tc--)
    solve();
}
