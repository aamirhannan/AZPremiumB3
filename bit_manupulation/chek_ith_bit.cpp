#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{
    int x, i;
    cin>>x>>i;

    if ((x >> i) & 1){
        cout<<"YES\n";
    }
    else{
        cout<<"No"<<endl;
    }
}

signed main()
{

    ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int tc; cin >> tc;
    // while (tc--)
      solve();
}
