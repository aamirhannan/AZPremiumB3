#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


int binarySearchAscending(vector<int>& arr, int target, int left, int right) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}

int binarySearchDescending(vector<int>& arr, int target, int left, int right) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}


int check(int x, vector<int>&nums, int n)
{
	if (x == n - 1)	return 1;
	if (nums[x] > nums[x + 1])	return 1;
	else	return 0;
}

int find_peak(int n, vector<int>&nums)
{
	int l = 0, h = n - 1, ans = 0;
	while (l <= h)
	{
		int mid = l + (h - l) / 2;
		if (check(mid, nums, n))
		{
			ans = mid;
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	int peak = find_peak(n, nums);


	while (q--)
	{
		int a;
		cin >> a;

		if (a == nums[peak]) {
			cout << peak + 1 << endl;
		}
		else {
			int leftResult = binarySearchAscending(nums, a, 0, peak);
			if (leftResult != -1) {
				cout << leftResult + 1 << " ";
			}

			int rightResult = binarySearchDescending(nums, a, peak + 1, nums.size() - 1);
			if (rightResult != -1) {
				cout << rightResult  + 1 << " ";
			}
			cout << endl;
		}
	}
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
