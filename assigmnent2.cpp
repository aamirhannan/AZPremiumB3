// Check if a given word or a given sentence is a palindrome (eg: “Mr. Owl ate my metal worm”)
// - Ignore case
// - Ignore special characters, consider only alphanumeric characters


// Mr. Owl ate my metal worm
// MrOwlatemymetalworm

#include <bits/stdc++.h>
using namespace std;


bool isPallindrome(string temp)
{
	int i = 0, j = temp.size() - 1;

	while (i <= j)
	{
		if (temp[i] != temp[j]) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}

bool checkPallindrome(string s)
{
	string temp = "";
	for (char i : s)
	{
		if ((i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z') or (i >= '0' and i <= '9'))
		{
			if (i >= 'A' and i <= 'Z')
			{
				temp += i + 32;
			}
			else {
				temp += i;
			}
		}
	}

	cout << temp << endl;

	if (isPallindrome(temp)) {
		return 1;
	}

	return 0;
}



int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "Mr. Owl ate my metal worm";
	string k = s;
	reverse(k.being(), k.end());
	if ()
		cout << checkPallindrome(s);
}
