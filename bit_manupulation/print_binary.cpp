#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void solve()
{
    unsigned int n;
    cin>>n;
    for(int i = 31; i>=0;i--){
        if(n&(1<<i)){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    cout<<endl;
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
