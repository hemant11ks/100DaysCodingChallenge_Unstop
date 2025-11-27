#include <bits/stdc++.h>
using namespace std;

long long int compareBits(string a, string b) {
    int n = a.size(), m = b.size();

    long long diff = 0, total = 0;

    // Compare a[j] with b[j]
    for (int j = 0; j < n; j++) {
        if (a[j] != b[j]) diff++;
    }
    total += diff;

    // Slide window from b[1..n], b[2..n+1] ... b[m-n..m-1]
    for (int i = 1; i <= m - n; i++) {

        // subtract outgoing character comparison
        if (a[0] != b[i - 1]) diff--;

        // add incoming character comparison
        if (a[n - 1] != b[i + n - 1]) diff++;

        // Now shift alignment:
        // Instead of comparing a[j] with b[i + j], adjust for new offsets:
        // But we must compute internal structure
        // So recompute difference array-like:

        diff = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] != b[i + j]) diff++;
        }

        total += diff;
    }

    return total;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << compareBits(a, b);
    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/250546?moduleId=407