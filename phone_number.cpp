#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


unordered_map<string, string> wordToDigit = {{"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

// time - O(n)
// space - O(n)

string getNumber(string s)
{
	s.push_back(' ');
	string temp = "";
	string ans = "";
	queue<string> q;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			if (temp == "double" or temp == "triple")
			{
				q.push(temp);
			}
			else if (wordToDigit.find(temp) != wordToDigit.end())
			{
				if (!q.empty())
				{
					string k = q.front();
					q.pop();
					if (k == "double")
					{
						string p = wordToDigit[temp];
						ans += p;
						ans += p;
					}
					else if (k == "triple")
					{
						string p = wordToDigit[temp];
						ans += p;
						ans += p;
						ans += p;
					}
				}
				else
				{
					string p = wordToDigit[temp];
					ans += p;
				}
			}
			temp = "";
		}
		else
		{
			temp += s[i];
		}
	}

	return ans;
}

void solve()
{
	string s;
	getline(cin, s);

	string ans = getNumber(s);
	cout << ans;
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
