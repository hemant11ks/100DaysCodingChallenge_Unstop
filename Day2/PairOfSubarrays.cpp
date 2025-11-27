#include <bits/stdc++.h>
using namespace std;

long long calculate_pairs(int n, vector<int>& arr) {
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + arr[i - 1];

    // map sum -> vector of (l, r) intervals
    unordered_map<long long, vector<pair<int,int>>> mp;
    mp.reserve(n * 2);

    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            long long sum = pref[r] - pref[l - 1];
            mp[sum].push_back({l, r});
        }
    }

    long long ans = 0;

    for (auto &kv : mp) {
        auto &v = kv.second;
        if (v.size() < 2) continue;

        // sort by r (ending index)
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        // for binary search, collect all l-values
        vector<int> starts;
        starts.reserve(v.size());
        for (auto &p : v) starts.push_back(p.first);

        for (int i = 0; i < v.size(); i++) {
            int r = v[i].second;

            // find first interval with l > r
            int idx = upper_bound(starts.begin(), starts.end(), r) - starts.begin();

            ans += (v.size() - idx);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << calculate_pairs(n, arr) << endl;
    return 0;
}


// Link to Problem : https://unstop.com/code/challenge-assessment/305915?moduleId=406