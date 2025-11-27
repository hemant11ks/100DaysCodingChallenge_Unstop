#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string s;
        cin >> s;

        bool valid = true;
        int i = 0;

        while (i < N) {
            if (s[i] == 'W') {
                i++;
                continue;
            }

            // Found a colored block
            bool hasB = false, hasR = false;

            while (i < N && s[i] != 'W') {
                if (s[i] == 'B') hasB = true;
                if (s[i] == 'R') hasR = true;
                i++;
            }

            // Block with only one color is invalid
            if (!hasB || !hasR) {
                valid = false;
                break;
            }
        }

        cout << (valid ? "YES" : "NO") << "\n";
    }
    return 0;
}

// Link to Problem : https://unstop.com/code/challenge-assessment/301659?moduleId=406