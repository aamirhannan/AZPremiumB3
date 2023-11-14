#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Resident {
	int max_shares;
	int cost_to_share;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {
		int n, p;
		cin >> n >> p;

		vector<Resident> residents(n);
		for (int i = 0; i < n; i++) {
			cin >> residents[i].max_shares;
		}

		for (int i = 0; i < n; i++) {
			cin >> residents[i].cost_to_share;
		}

		// Create a min-heap (priority queue) to keep track of residents based on their costs
		priority_queue<pair<long long, int>> pq;

		long long total_cost = 0;
		long long current_shares = 0;

		for (int i = 0; i < n; i++) {
			// Calculate the difference between the maximum shares and the current shares
			long long shares_needed = max(0, residents[i].max_shares - current_shares);

			// Calculate the cost to directly inform this resident
			long long cost_direct = shares_needed * 1LL * p;

			// Add this resident to the priority queue with the cost to directly inform
			pq.push({ -cost_direct, i});

			// Update the total cost and current shares
			total_cost += cost_direct;
			current_shares += shares_needed;

			if (current_shares >= n) {
				break; // All residents have been informed
			}

			// Check if other residents can share the announcement
			while (!pq.empty()) {
				auto [cost, idx] = pq.top();
				cost = -cost; // Convert back to positive
				pq.pop();

				// If the resident can share the announcement, calculate the cost
				if (current_shares < n && residents[idx].max_shares > 0) {
					long long shares_to_share = min(residents[idx].max_shares, n - current_shares);
					long long cost_to_share = shares_to_share * residents[idx].cost_to_share;

					// Add the cost to the total cost and update current_shares
					total_cost += cost_to_share;
					current_shares += shares_to_share;

					// Update the maximum shares for this resident
					residents[idx].max_shares -= shares_to_share;

					// Re-add this resident to the priority queue if they can share more
					if (residents[idx].max_shares > 0) {
						pq.push({ -cost_to_share, idx});
					}
				}
			}
		}

		cout << total_cost << endl;
	}

	return 0;
}
