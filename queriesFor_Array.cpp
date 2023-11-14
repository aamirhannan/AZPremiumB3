#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

#include <iostream>
#include <string>

using namespace std;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;

    int n = s.length();
    int count_plus = 0;
    int count_minus = 0;
    bool is_sorted = true;

    for (int j = 0; j < n; j++) {
      if (s[j] == '+') {
        count_plus++;
      } else if (s[j] == '-') {
        count_minus++;
      } else if (s[j] == '1') {
        if (!is_sorted) {
          break;
        }
        is_sorted = (count_plus >= count_minus);
      } else {
        is_sorted = false;
        break;
      }
    }

    if (is_sorted && count_plus >= count_minus) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}

