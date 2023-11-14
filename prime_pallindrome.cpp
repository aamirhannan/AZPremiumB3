#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


bool isPalindrome(int num) {
	int original = num;
	int reversed = 0;

	while (num > 0) {
		int digit = num % 10;
		reversed = reversed * 10 + digit;
		num /= 10;
	}

	return original == reversed;
}

void solve()
{
	int a, b, cnt = 0;
	cin >> a >> b;
	vector<int>isPrime(b + 1, 1);

	for (int i = 2; i <= b; i++)
	{
		if (isPrime[i]) {

			for (int j = i * i; j <= b; j += i )
			{
				isPrime[j] = 0;
			}
		}
	}

	for (int i = a; i <= b; i++)
	{
		if (isPalindrome(i) and isPrime[i] == 1)
		{
			cnt++;
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

	// int tc;
	// cin >> tc;
	// while (tc--)
	// {
	solve();
	// }
}
