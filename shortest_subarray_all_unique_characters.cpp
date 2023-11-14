#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int freq[1000100];
int dist_cnt = 0;

int distint_element(vector<int>&nums)
{
    unordered_set<int> st;
    for(int i = 0; i < nums.size(); i++){
        st.insert(nums[i]);
    }

    return st.size();
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]] = 0;
    }
    int k = distint_element(arr);
    
    int head = -1, tail = 0;
    int ans = INF;

    while (tail < n)
    {
        // Step 1: eat as many element as possible for this tail
        while (head + 1 < n && (dist_cnt + 1 <= (k - 1) || freq[arr[head + 1]] > 0))
        {
            head++;

            // insert the new element in the datastructure.
            if (freq[arr[head]] == 0)
                dist_cnt++;
            freq[arr[head]]++;
        }

        // Step 2: Register the length
        if (head + 1 < n)
        { // if there is a next element to take.
            // taking that will make exactly k disticnt.
            ans = min(ans, (head - tail + 1) + 1);
        }

        // Step 3: Move tail forward
        if (head >= tail)
        {
            // remove the new element in the datastructure.
            freq[arr[tail]]--;
            if (freq[arr[tail]] == 0)
                dist_cnt--;

            tail++;
        }
        else
        {
            // if the snake is empty
            tail++;
            head = tail - 1;
        }
    }
    cout << ans << endl;
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
