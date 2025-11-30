#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    unordered_map<long long, long long> freq;

    while (Q--) {
        long long A, B;
        cin >> A >> B;
        freq[B] += A;
    }

    if (freq.size() <= 1) {
        cout << 0;
        return 0;
    }

    long long minFreq = LLONG_MAX, maxFreq = LLONG_MIN;
    long long minNum = LLONG_MAX, maxNum = LLONG_MIN;

    for (auto &p : freq) {
        long long num = p.first;
        long long f = p.second;

        // Lowest frequency logic
        if (f < minFreq || (f == minFreq && num < minNum)) {
            minFreq = f;
            minNum = num;
        }

        // Highest frequency logic
        if (f > maxFreq || (f == maxFreq && num > maxNum)) {
            maxFreq = f;
            maxNum = num;
        }
    }

    cout << llabs(maxNum - minNum);
    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250902?moduleId=409