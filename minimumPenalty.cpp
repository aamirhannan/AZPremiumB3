#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int freq[1000001] = {0};

void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for (auto &i : arr) {cin>>i;}

    int ans = k;
    int start = 0;
    int current = 0;
    int currSum = 0;
    while(current < n)
    {
        if(freq[arr[current]] == 0)
            currSum++;
        freq[arr[current]]++;
        if(current >= k){
            freq[arr[current-k]]--;
            if(freq[arr[current-k]] == 0)
                currSum--;
        }
        if(current >= k - 1)
            ans = min(ans, currSum);
        current++;
    }

    for (int i = n - k; i < n; i++) // only the frequency of last d element is set, so for next testcase making it zero.
        freq[arr[i]]--;

    cout<<ans<<endl;

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
