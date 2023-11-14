#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
        int i = 0;
        int k = n - 1;
        while (i < j && j < k)
        {
            if (arr[i] + arr[j] + arr[k] == target )
            {
                int itemp = i;
                int ktemp = k;
                while (itemp < j && arr[itemp] == arr[i]) {
                    itemp++;
                }

                while (ktemp > j && arr[ktemp] == arr[k]) {
                    ktemp--;
                }

                cnt += abs(itemp - i) * abs(k - ktemp);

                i = itemp;
                k = ktemp;
            }
            else if (arr[i] + arr[j] + arr[k] < target)
            {
                i++;
            }
            else {
                k--;
            }
        }
    }

    cout << cnt << endl;
}

signed main()
{

    ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc; cin >> tc;
    while (tc--)
        solve();
}
