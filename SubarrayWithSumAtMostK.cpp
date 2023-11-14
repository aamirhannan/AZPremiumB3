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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int head = 0, tail = 0, ans = 0, dist_cnt = 0;

    while (head < n)
    {
        dist_cnt += arr[head];

        while (tail <= head and dist_cnt > k)
        {

            dist_cnt -= arr[tail];

            tail++;
        }
        ans += head - tail + 1;
        head++;
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

    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}