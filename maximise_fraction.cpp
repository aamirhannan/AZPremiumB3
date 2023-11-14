#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ld long double

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
const double EPS = 1e-9;

bool check(ld x, int n, vector<double>&a, vector<double>&b, int k)
{
    vector<double>result;
    for (int i = 0; i < n; i++)
    {
        result.push_back(a[i] - x * b[i]);
    }

    sort(result.rbegin(), result.rend());

    ld sum = 0.0;
    for (int i = 0; i < k; i++)
    {
        sum += result[i];
    }

    return sum >= 0.0;
}

void solve()
{

    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    vector<double> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }


    ld l = 0.0, h = 1e9, ans = 0.0;

    while (abs(h - l) >= EPS)
    {
        long double mid = (l + h) / 2.0;
        if (check(mid, n, a, b, k))
        {
            ans = mid;
            l = mid;
        }
        else {
            h = mid;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;

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
