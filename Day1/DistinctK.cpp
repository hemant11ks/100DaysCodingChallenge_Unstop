#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> arr(N);
    unordered_map<string, int> freq;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int k;
    cin >> k;

    vector<string> uniqueStrings;
    for (int i = 0; i < N; i++) {
        if (freq[arr[i]] == 1) {   // Only distinct elements
            uniqueStrings.push_back(arr[i]);
        }
    }

    if (uniqueStrings.size() < k) {
        cout << -1;
    } else {
        cout << uniqueStrings[k - 1];
    }

    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250739?moduleId=372