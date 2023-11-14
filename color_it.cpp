#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


int binary_search_lower(const vector<int>& arr, int target) {
	int left = 0, right = arr.size() - 1;
	int result = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] < target) {
			result = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return result;
}

int distinct_colorings(int N, int M, int K) {
	vector<int> dp(K + 1, 0);
	vector<int> prefix_sum(K + 2, 0);

	dp[1] = 1;
	prefix_sum[1] = 1;
	prefix_sum[2] = 1;

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			int lower_idx = binary_search_lower(prefix_sum, j);
			int upper_idx = min(j - 1, M);
			int count = (prefix_sum[upper_idx + 2] - prefix_sum[lower_idx + 2] + MOD) % MOD;
			dp[j] = count;
		}

		prefix_sum[1] = dp[1];
		for (int j = 2; j <= K + 1; ++j) {
			prefix_sum[j] = (prefix_sum[j - 1] + dp[j]) % MOD;
		}
	}

	return dp[K];
}



signed main()
{

	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		int N, M, K;
		cin >> N >> M >> K;

		int result = distinct_colorings(N, M, K);
		cout << result << endl;
	}

	return 0;
}
